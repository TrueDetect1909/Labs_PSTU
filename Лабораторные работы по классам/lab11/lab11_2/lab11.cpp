#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;
};

bool operator==(const Time& t1, const Time& t2) {
    return t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds;
}

bool operator<(const Time& t1, const Time& t2) {
    if (t1.hours != t2.hours) {
        return t1.hours < t2.hours;
    }
    if (t1.minutes != t2.minutes) {
        return t1.minutes < t2.minutes;
    }
    return t1.seconds < t2.seconds;
}

Time operator-(const Time& t1, const Time& t2) {
    int h = t1.hours - t2.hours;
    int m = t1.minutes - t2.minutes;
    int s = t1.seconds - t2.seconds;
    if (s < 0) {
        s += 60;
        m--;
    }
    if (m < 0) {
        m += 60;
        h--;
    }
    return { h, m, s };
}

void addTime(vector<Time>& container, const Time& key, int position) {
    auto it = find(container.begin(), container.end(), key);
    if (it != container.end()) {
        container.insert(container.begin() + position, *it);
    }
}

void removeTime(vector<Time>& container, const Time& key) {
    auto it = find(container.begin(), container.end(), key);
    if (it != container.end()) {
        container.erase(it);
    }
}

void subtractMinMax(vector<Time>& container) {
    auto minmax = minmax_element(container.begin(), container.end());
    Time diff = *minmax.second - *minmax.first;
    for (auto& t : container) {
        t = t - diff;
    }
}

void printContainer(const vector<Time>& container) {
    for (const auto& t : container) {
        cout << t.hours << ":" << t.minutes << ":" << t.seconds << " ";
    }
    cout << endl;
}

int main() {
    vector<Time> container = { {10, 30, 0}, {8, 15, 0}, {12, 45, 0}, {9, 0, 0} };
    printContainer(container);
    addTime(container, { 8, 15, 0 }, 2);
    printContainer(container);
    removeTime(container, { 10, 30, 0 });
    printContainer(container);
    subtractMinMax(container);

    printContainer(container);

    return 0;
}
