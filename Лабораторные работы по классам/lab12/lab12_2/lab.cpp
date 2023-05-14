#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// Определение пользовательского типа Time
class Time {
public:
    int hours;
    int minutes;
    int seconds;

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Перегрузка оператора < для использования в ассоциативном контейнере
    bool operator<(const Time& other) const {
        if (hours != other.hours) {
            return hours < other.hours;
        }
        if (minutes != other.minutes) {
            return minutes < other.minutes;
        }
        return seconds < other.seconds;
    }

    // Перегрузка оператора << для вывода элементов типа Time
    friend ostream& operator<<(ostream& os, const Time& time) {
        os << time.hours << ":" << time.minutes << ":" << time.seconds;
        return os;
    }
};

// Глобальная функция для создания и заполнения ассоциативного контейнера
void fillMap(map<Time, int>& timeMap) {
    timeMap[Time(10, 30, 0)] = 1;
    timeMap[Time(12, 0, 0)] = 2;
    timeMap[Time(15, 45, 0)] = 3;
    timeMap[Time(18, 15, 0)] = 4;
    timeMap[Time(20, 30, 0)] = 5;
}

// Глобальная функция для добавления элемента в заданную позицию контейнера
void insertElement(map<Time, int>& timeMap, Time key, int value, int position) {
    auto it = timeMap.find(key);
    if (it != timeMap.end()) {
        timeMap.erase(it);
    }
    auto insertIt = timeMap.begin();
    advance(insertIt, position - 1);
    timeMap.insert(insertIt, make_pair(key, value));
}

// Глобальная функция для удаления элемента с заданным ключом из контейнера
void removeElement(map<Time, int>& timeMap, Time key) {
    auto it = timeMap.find(key);
    if (it != timeMap.end()) {
        timeMap.erase(it);
    }
}

// Глобальная функция для вычисления разницы между максимальным и минимальным элементами контейнера
// и вычитания этой разницы из каждого элемента контейнера
void subtractDifference(map<Time, int>& timeMap) {
    auto minMax = minmax_element(timeMap.begin(), timeMap.end());
    int difference = minMax.second->second - minMax.first->second;
    for (auto& pair : timeMap) {
        pair.second -= difference;
    }
}

int main() {
    map<Time, int> timeMap;
    fillMap(timeMap);
    setlocale(0, "");
    // Вывод исходного контейнера
    cout << "Исходный контейнер:" << endl;
    for (auto& pair : timeMap) {
        cout << pair.first << " - " << pair.second << endl;
    }

    // Добавление элемента в заданную позицию
    Time insertKey(14, 30, 0);
    int insertValue = 6;
    int insertPosition = 3;
    insertElement(timeMap, insertKey, insertValue, insertPosition);
    cout << endl << "Контейнер после добавления элемента " << insertKey << " на позицию " << insertPosition << ":" << endl;
    for (auto& pair : timeMap) {
        cout << pair.first << " - " << pair.second << endl;
    }

    // Удаление элемента с заданным ключом
    Time removeKey(15, 45, 0);
    removeElement(timeMap, removeKey);
    cout << endl << "Контейнер после удаления элемента " << removeKey << ":" << endl;
    for (auto& pair : timeMap) {
        cout << pair.first << " - " << pair.second << endl;
    }

    // Вычисление разницы между максимальным и минимальным элементами и вычитание этой разницы из каждого элемента
    subtractDifference(timeMap);
    cout << endl << "Контейнер после вычитания разницы между максимальным и минимальным элементами:" << endl;
    for (auto& pair : timeMap) {
        cout << pair.first << " - " << pair.second << endl;
    }

    return 0;
}
