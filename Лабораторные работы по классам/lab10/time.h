#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Time {
private:
    int minutes;
    int seconds;
public:
    Time() {
        minutes = 0;
        seconds = 0;
    }
    Time(int m, int s) {
        minutes = m;
        seconds = s;
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
    }
    friend ostream& operator<<(ostream& os, const Time& t) {
        os << t.minutes << ":" << t.seconds;
        return os;
    }
    friend istream& operator>>(istream& is, Time& t) {
        is >> t.minutes >> t.seconds;
        if (t.seconds >= 60) {
            t.minutes += t.seconds / 60;
            t.seconds %= 60;
        }
        return is;
    }
    Time operator+(const int& s) {
        Time t(minutes, seconds + s);
        return t;
    }
    Time operator-(const int& s) {
        Time t(minutes, seconds - s);
        if (t.seconds < 0) {
            t.minutes -= 1;
            t.seconds += 60;
        }
        return t;
    }
    Time operator-(const Time& t2) {
        int s1 = minutes * 60 + seconds;
        int s2 = t2.minutes * 60 + t2.seconds;
        int diff = s1 - s2;
        if (diff < 0) {
            diff = 0;
        }
        Time t(diff / 60, diff % 60);
        return t;
    }
    bool operator==(const Time& t2) {
        return (minutes == t2.minutes && seconds == t2.seconds);
    }
    bool operator!=(const Time& t2) {
        return (minutes != t2.minutes || seconds != t2.seconds);
    }
    Time operator--() {
        if (minutes > 0 || seconds >= 90) {
            seconds -= 90;
            if (seconds < 0) {
                minutes -= 1;
                seconds += 60;
            }
        }
        return *this;
    }
    Time operator++() {
        seconds += 60;
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        return *this;
    }
};

void createObject(vector<Time>& times) {
    Time t;
    cout << "Enter minutes and seconds: ";
    cin >> t;
    times.push_back(t);
}

void saveObjects(vector<Time>& times) {
    ofstream file("times.txt");
    for (int i = 0; i < times.size(); i++) {
        file << times[i] << endl;
    }
    file.close();
}

void readObjects(vector<Time>& times) {
    ifstream file("times.txt");
    Time t;
    while (file >> t) {
        times.push_back(t);
    }
    file.close();
}

void deleteObjects(vector<Time>& times) {
    Time t;
    cout << "Enter minutes and seconds to delete: ";
    cin >> t;
    for (int i = 0; i < times.size(); i++) {
        if (times[i] == t) {
            times.erase(times.begin() + i);
            i--;
        }
    }
}

void decreaseObjects(vector<Time>& times) {
    Time t;
    cout << "Enter minutes and seconds to decrease: ";
    cin >> t;
    for (int i = 0; i < times.size(); i++) {
        if (times[i] == t) {
            --times[i];
        }
    }
}

void addObjects(vector<Time>& times) {
    Time t;
    cout << "Enter minutes and seconds to add after: ";
    cin >> t;
    int k;
    cout << "Enter number of objects to add: ";
    cin >> k;
    for (int i = 0; i < times.size(); i++) {
        if (times[i] == t) {
            for (int j = 0; j < k; j++) {
                createObject(times);
            }
            break;
        }
    }
}