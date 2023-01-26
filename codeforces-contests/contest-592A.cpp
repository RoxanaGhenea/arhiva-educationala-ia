//https://codeforces.com/contest/1244/problem/A - Link

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b, c, d, k, x, y;

        cin >> a >> b >> c >> d >> k;
        if (a % c == 0) {
            x = a / c;
        } else {
            x = a / c + 1;
        }

        if (b % d == 0) {
            y = b / d;
        } else {
            y = b / d + 1;
        }
        
        if (x + y <= k) {
            cout << x << " " << y << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}