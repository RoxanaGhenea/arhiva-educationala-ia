//https://codeforces.com/contest/1277/problem/A

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1277A.in", "r", stdin);
    freopen("contest-1277A.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; ++i) {
        int age, cnt = 0;
        long long number;
        cin >> age;
        for (int j = 1; j <= 9; ++j) {
            number = j;
            while (number <= age) {
                cnt += 1;
                number = number * 10 + j;
            }
        }
        cout << cnt << "\n";
    }
}