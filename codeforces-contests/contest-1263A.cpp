//https://codeforces.com/contest/1263/problem/A

#include <bits/stdc++.h>

using namespace std;
int candies[5];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1263A.in", "r", stdin);
    freopen("contest-1263A.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; ++i) {
        int cnt = 0;
        cin >> candies[0] >> candies[1] >> candies[2];
        sort (candies, candies + 3);
        if (candies[2] <= candies[0] + candies[1]) {
            cnt = (candies[0] + candies[1] + candies[2]) / 2;
        } else {
            cnt = candies[0] + candies[1];
        }
        cout << cnt << "\n";
    }
}