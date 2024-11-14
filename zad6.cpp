#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>
#include <utility>

using namespace std;

// Класс для представления графа
class Graph {
public:
    // Хеш-таблица для хранения маршрутов и задержек
    unordered_map<string, unordered_map<string, int>> adjList;

    // Метод для добавления маршрута
    void addRoute(const string& from, const string& to, int delay) {
        adjList[from][to] = delay; // Добавляем или обновляем задержку
    }

    // Метод для поиска минимальной задержки с использованием DFS
    int findMinDelay(const string& start, const string& end, int currentDelay, unordered_map<string, bool>& visited) {
        // Если достигли конечного сервера, возвращаем текущую задержку
        if (start == end) {
            return currentDelay;
        }

        // Помечаем текущий сервер как посещённый
        visited[start] = true;

        int minDelay = numeric_limits<int>::max(); // Инициализируем минимальную задержку как бесконечность

        // Проходим по всем соседям текущего сервера
        for (const auto& neighbor : adjList[start]) {
            if (!visited[neighbor.first]) { // Если сосед не был посещён
                int delay = findMinDelay(neighbor.first, end, currentDelay + neighbor.second, visited);
                minDelay = min(minDelay, delay); // Обновляем минимальную задержку
            }
        }

        // Убираем отметку о посещении текущего сервера
        visited[start] = false;

        return minDelay; // Возвращаем минимальную задержку
    }

    // Метод для поиска минимальной задержки
    int getMinDelay(const string& start, const string& end) {
        unordered_map<string, bool> visited; // Хранилище для посещённых узлов
        int result = findMinDelay(start, end, 0, visited);
        return (result == numeric_limits<int>::max()) ? -1 : result; // Если маршрут не найден, возвращаем -1
    }
};

int main() {
    Graph graph;

    int numRoutes;
    cout << "Введите количество маршрутов: ";
    cin >> numRoutes;

    for (int i = 0; i < numRoutes; ++i) {
        string from, to;
        int delay;
        cout << "Введите маршрут (формат: от до задержка): ";
        cin >> from >> to >> delay;
        graph.addRoute(from, to, delay);
    }

    string start, end;
    cout << "Введите начальный сервер: ";
    cin >> start;
    cout << "Введите конечный сервер: ";
    cin >> end;

    int minDelay = graph.getMinDelay(start, end);
    if (minDelay != -1) {
        cout << "Минимальная задержка от " << start << " до " << end << " = " << minDelay << endl;
    } else {
        cout << "Маршрут не найден." << endl;
    }

    return 0;
}
