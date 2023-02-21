//https://codeforces.com/contest/1253

#include <bits/stdc++.h>

using namespace std;
int a[100005];
int b[100005];
int diff[100005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1253A.in", "r", stdin);
    freopen("contest-1253A.out", "w", stdout);
    #endif

    int testCases;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i) {
        int n, cnt = 0, negatives = 0;
        cin >> n; 
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        for (int i = 1; i <= n; ++i) {
            diff[i] = b[i] - a[i];
            if (diff[i] < 0) {
                negatives += 1;
            }
        }

        int p = 1;
        while (p <= n) {
            if (diff[p] == 0) {
                p += 1;
            } else {
                cnt += 1;
                p = p + 1;
                while (diff[p] == diff[p - 1] and p <= n) {
                    p += 1;
                }
            }
        }

        if (negatives > 0) {
            cout << "NO" << "\n";
        } else if (cnt >= 2) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}