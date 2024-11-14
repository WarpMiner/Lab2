#include "include/set.h"
int main() {
    int N;
    cout << "Введите количество черепах: ";
    cin >> N;

    Set<int> possibleCounts; // Множество для хранения возможных количеств черепах
    set<pair<int, int>> turtles; // Создаем множество для пар

    // Вводим данные о черепахах
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;

        turtles.insert(make_pair(a, b)); // Вставляем пару в множество
        
        // Вычисляем общее количество черепах для каждой черепахи
        int total = a + b + 1;
        possibleCounts.insert(total); // Добавляем в множество
    }

    // Максимальное количество черепах, которые могут говорить правду
    int maxTruthTurtles = 0;

    // Проверяем каждое возможное количество
    for (const auto& count : possibleCounts.getElements()) {
        // Подсчитываем количество черепах, которые могут говорить правду для данного count
        int truthCount = 0;
        for (const auto& turtle : turtles) {
            if (turtle.first + turtle.second + 1 == count) {
                truthCount++;
            }
        }
        maxTruthTurtles = max(maxTruthTurtles, truthCount);
    }

    cout << "Максимальное количество черепах, которые могут говорить правду: " << maxTruthTurtles << endl;

    return 0;
}
