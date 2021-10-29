#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int number, x;
int minimum = 1;
int maximum = 100;
int count = 0;
bool f = false;

int main() {
    setlocale(LC_ALL, "");
    
    srand(time(NULL));
    number = minimum + rand() % (maximum - minimum + 1);

    cout << "Я загадал число от 1 до 100. Попробуй угадать!" << endl;

    while (count!=7 && f==false) {
        count++;
        cout << "Введите свой вариант: ";
        cin >> x;

        if (x>number) cout << "Ваше число больше, чем загаданное. Количество оставшихся попыток: " << 7-count << endl << endl;
        else if (x<number) cout << "Ваше число меньше, чем загаданное. Количество оставшихся попыток: " << 7-count << endl << endl;
        else f = true;

    }
    if (f==true) cout << "Вы угадали число. Количество потребовшихся попыток: " << count << endl << endl;
    else cout << "Ваши попытки кончились. Вы не смогли угадать число. Загаданное число = " << number << endl << endl;

    system("pause");
    return 0;
}