//https://codeforces.com/contest/1255/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1255A.in", "r", stdin);
    freopen("contest-1255A.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;
    
    for (int i = 1; i <= testCase; ++i) {
        int a, b, countPresses = 0;
        cin >> a >> b;

        if (a == b) {
            countPresses = 0;
        }
        int diff = abs (a - b);
        if (diff >= 5) {
            int result = diff / 5;
            countPresses += result;
            diff = diff % 5;
        }
        if (diff < 5) {
            int result = diff / 2;
            diff = diff % 2;
            countPresses += result + diff;
        }
        cout << countPresses << "\n";
    }
}