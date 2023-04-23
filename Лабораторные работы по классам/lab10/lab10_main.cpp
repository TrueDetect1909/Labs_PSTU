#include <iostream>
#include "time.h"
using namespace std;
int main() {
    vector<Time> times;
    int choice;
    do {
        cout << "1. Create object\n";
        cout << "2. Save objects\n";
        cout << "3. Read objects\n";
        cout << "4. Delete objects\n";
        cout << "5. Decrease objects\n";
        cout << "6. Add objects\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            createObject(times);
            break;
        case 2:
            saveObjects(times);
            break;
        case 3:
            readObjects(times);
            for (int i = 0; i < times.size(); i++) {
                cout << times[i] << endl;
            }
            break;
        case 4:
            deleteObjects(times);
            break;
        case 5:
            decreaseObjects(times);
            break;
        case 6:
            addObjects(times);
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 7);
    return 0;
}