//https://codeforces.com/contest/1278/problem/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1278B.in", "r", stdin);
    freopen("contest-1278B.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; ++i) {
        long long a, b, increment = 1;
        int cnt = 0;
        cin >> a >> b;
        int diff = abs(a - b);
        while (diff > 0) {
            diff -= increment;
            cnt += 1;
            increment += 1;
        }
        while (abs(diff % 2) == 1) {
            diff -= increment;
            cnt += 1;
            increment += 1;
        }
        cout << cnt << '\n';
    }
}