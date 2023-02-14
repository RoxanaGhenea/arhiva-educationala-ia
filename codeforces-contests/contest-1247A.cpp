#include <iostream>

using namespace std;

int main()
{
    int da, db, dif, a , b;
    cin >> da >> db;
    dif = db - da;
    if (dif == 0) {
        a = da * 10;
        b = a + 1;
        cout << a << " " << b;
    } else if (dif == 1) {
        b = db * 10;
        a = b - 1;
        cout << a << " " << b;
    } else if (da == 9 & db == 1) {
        b = db * 10;
        a = da;
        cout << a << " " << b;
    } else {
        cout << -1;
    }
}