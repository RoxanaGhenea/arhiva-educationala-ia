//https://codeforces.com/contest/1257/problem/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen ("contest-1257B.in", "r", stdin);
    freopen ("contest-1257B.out", "w", stdout);
    #endif

    int testCases;

    cin >> testCases;

    for (int i = 1; i <= testCases; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < 4) {
            if (x > 1 and y < 4 and x <= y) {
                cout << "YES" << "\n";
            } else if (x >= y) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else {
            cout << "YES" << "\n";  
        }
    }
}