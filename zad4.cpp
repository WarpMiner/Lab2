#include "include/array.h"

struct Histo {
    char symbol;
    int frequence;
};

void BuildHist(string& str) {
    Array<Histo> frequencies;
    int uniqueCount = 0;

    for (char ch : str) {
        if (ch != ' ' && ch != '\n') { // Игнорируем пробелы и переводы строк
            bool found = false;
            for (size_t i = 0; i < frequencies.length(); ++i) {
                if (frequencies.get(i).symbol == ch) {
                    frequencies.replace(i, {ch, frequencies.get(i).frequence + 1});
                    found = true;
                    break;
                }
            }
            if (!found) {
                frequencies.add({ch, 1});
            }
        }
    }

    // Сортировка по кодам
    for (size_t i = 0; i < frequencies.length() - 1; ++i) {
        for (size_t j = 0; j < frequencies.length() - i - 1; ++j) {
            if (frequencies.get(j).symbol > frequencies.get(j + 1).symbol) {
                Histo temp = frequencies.get(j);
                frequencies.replace(j, frequencies.get(j + 1));
                frequencies.replace(j + 1, temp);
            }
        }
    }

    // Находим максимальную высоту
    int maxHeight = 0;
    for (size_t i = 0; i < frequencies.length(); ++i) {
        if (frequencies.get(i).frequence > maxHeight) {
            maxHeight = frequencies.get(i).frequence;
        }
    }

    // Создаем гистограмму
    for (int height = maxHeight; height > 0; --height) {
        for (size_t i = 0; i < frequencies.length(); ++i) {
            if (frequencies.get(i).frequence >= height) {
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        cout << endl; // Переход на новую строку после каждой высоты
    }

    // Выводим гистограмму
    for (size_t i = 0; i < frequencies.length(); ++i) {
        cout << frequencies.get(i).symbol;
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Введите сообщение: ";
    getline(cin, str);

    BuildHist(str);
    return 0;
}
