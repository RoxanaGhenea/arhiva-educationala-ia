//https://codeforces.com/contest/1238/problem/A - Link 
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        long long x,y;
        cin >> x >> y;
        if (x - y == 1) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}