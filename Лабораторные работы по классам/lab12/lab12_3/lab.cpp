#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset<double> mySet;

void fillSet() {
    mySet.insert(1.2);
    mySet.insert(3.4);
    mySet.insert(5.6);
    mySet.insert(7.8);
}

void addElement(double key, int position) {
    auto it = mySet.find(key);
    if (it != mySet.end()) {
        advance(it, position);
        mySet.insert(it, key);
    }
}

void removeElement(double key) {
    mySet.erase(key);
}

void subtractMinMax() {
    double min = *mySet.begin();
    double max = *mySet.rbegin();
    double diff = max - min;
    multiset<double> updatedSet;
    for (auto& elem : mySet) {
        updatedSet.insert(elem + diff);
    }
    mySet = updatedSet;

}

int main() {
    fillSet();
    for (auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    addElement(3.4, 2);
    for (auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    removeElement(5.6);
    for (auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    subtractMinMax();
    for (auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
