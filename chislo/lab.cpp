#include <iostream>

int x,a,b,c;

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "Введите трехзначное число, в котором не будет повторяющихся чисел: ";
    cin >> x;

    while (x<100 || x>999) {
        cout << endl <<"Вы ввели не трехзначное число. Введите трехзначное число, в котором не будет повторяющихся цифр: ";
        cin >> x;
    }

    a = x%10;
    x = x/10;
    b = x%10;
    c = x/10;
        
    while ((a==b) || (a==c) || (b==c)) {
        cout << endl <<"В вашем числе есть повторяющиеся цифр. Введите трехзначное число, в котором не будет повторяющихся чисел: ";
        cin >> x;

        while (x<100 || x>999) {
            cout << endl <<"Вы ввели не трехзначное число. Введите трехзначное число, в котором не будет повторяющихся цифр: ";
            cin >> x;
        }

        a = x%10;
        x = x/10;
        b = x%10;
        c = x/10;
        }

    cout << endl <<"Все возможные комбинации числа:";

    if (a == 0) {
        cout << " " << b << a << c << ",";
        cout << " " << b << c << a << ",";
        cout << " " << c << a << b << ",";
        cout << " " << c << b << a << ".";
    }
    if (b == 0) {
        cout << " " << a << b << c << ",";
        cout << " " << a << c << b << ",";
        cout << " " << c << a << b << ",";
        cout << " " << c << b << a << ".";
    }
    else {
        cout << " " << a << b << c << ",";
        cout << " " << a << c << b << ",";
        cout << " " << b << a << c << ",";
        cout << " " << b << c << a << ",";
        cout << " " << c << a << b << ",";
        cout << " " << c << b << a << ".";
    }
    
    cout << endl << endl <<"Самое большое число:";

    if (a>b && a>>c) {
        if (b>c) cout << " " << a << b << c;
        else cout << " " << a << c << b;
    }
    else {
        if (b>c) {
            if (a>c) cout << " " << b << a << c;
            else cout << " " << b << c << a;
        }
        else {
            if (a>b) cout << " " << c << a << b;
            else cout << " " << c << b << a;
        }
    }

    cout << endl << endl;

    system("pause");
    return 0;
}