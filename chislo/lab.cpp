#include <iostream>

int x,a,b,c;

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    
    cout << "������� ����������� �����, � ������� �� ����� ������������� �����: ";
    cin >> x;

    while (x<100 || x>999) {
        cout << endl <<"�� ����� �� ����������� �����. ������� ����������� �����, � ������� �� ����� ������������� ����: ";
        cin >> x;
    }

    a = x%10;
    x = x/10;
    b = x%10;
    c = x/10;
        
    while ((a==b) || (a==c) || (b==c)) {
        cout << endl <<"� ����� ����� ���� ������������� ����. ������� ����������� �����, � ������� �� ����� ������������� �����: ";
        cin >> x;

        while (x<100 || x>999) {
            cout << endl <<"�� ����� �� ����������� �����. ������� ����������� �����, � ������� �� ����� ������������� ����: ";
            cin >> x;
        }

        a = x%10;
        x = x/10;
        b = x%10;
        c = x/10;
        }

    cout << endl <<"��� ��������� ���������� �����:";

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
    
    cout << endl << endl <<"����� ������� �����:";

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