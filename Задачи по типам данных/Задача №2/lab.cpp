#include <iostream>

using namespace std;

int a, b, c, d, e, f;
int i;
int resh, resm, ress;

int vvod1(int x) {
    int hour;
    do
    {
        cout << "Введите количество часов для " << x << " времени: ";
        cin >> hour;
    } while (hour>23 || hour<0);
    
    return hour;

}
int vvod2(int x) {
    int minute;
    do
    {
        cout << "Введите количество минут для " << x << " времени: ";
        cin >> minute;
    } while (minute>59 || minute<0);
    
    return minute;

}
int vvod3(int x) {
    int second;
    do
    {
        cout << "Введите количество секунд для " << x << " времени: ";
        cin >> second;
    } while (second>59 || second<0);
    
    return second;

}

int main() {
    setlocale(LC_ALL, "");
    i++;
    a = vvod1(i);
    b = vvod2(i);
    c = vvod3(i);
    i++;
    d = vvod1(i);
    e = vvod2(i);
    f = vvod3(i);

    if (d<a) resh = (d+24)-a;
    else resh = d-a;
    if (e<b) {
        resm = (e+60)-b;
        resh--;
        if (resh<0) {
            resh = 23;
        }
        else;
    }
    else resm = e-b;
    if (f<c) {
        ress = (f+60)-c;
        resm--;
        if (resm<0) {
            resm = 59;
            resh--;
            if (resh<0) {
                resh = 23;
            }
            else;
        }
        else;
    }
    else ress = f-c;

    cout << "Первое время: " << a << ":" << b << ":" << c << endl;
    cout << "Второе время: " << d << ":" << e << ":" << f << endl;
    cout << "Разница между временами: " << resh << ":" << resm << ":" << ress << endl;

    system("pause");
    return 0;
}