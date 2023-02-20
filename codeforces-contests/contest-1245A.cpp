//https://codeforces.com/contest/1245/problem/A

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        swap(a,b);
    }
    if (b != 0) {
        gcd(a % b, b);
    } else {
        return a;
    }
}

int main()
{
    int tests;
    cin >> tests;

    for (int i = 1; i <= tests; ++i) {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) != 1) {
            cout << "Infinite" << "\n";
        } else {
            cout << "Finite" << "\n";
        }
    }
}