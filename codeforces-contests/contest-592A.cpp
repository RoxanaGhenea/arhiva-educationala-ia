//https://codeforces.com/contest/1244/problem/A - Link

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b, c, d, k;
        double x, y;

        cin >> a >> b >> c >> d >> k;
        if (a % c == 0) {
            x = a / c;
        } else {
            x = round(a/c + 0.5);
        }

        if (b % d == 0) {
            y = b / d;
        } else {
            y = round(b/d + 0.5);
        }
        
        if (x + y <= k) {
            cout << x << " " << y << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}