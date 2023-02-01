//https://codeforces.com/contest/1248/problem/A

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int q[100005];
int p[100005];

int main() 
{
    int test;
    cin >> test;

    for (int i = 1; i <= test; ++i) {
        int n,m, countIntegerPoints = 0;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> p[j];
        }
        cin >> m;
        for (int k = 1; k <= m; ++k) {
            cin >> q[k];
        }

        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) {
                double intersection;
                intersection = (q[k] - p[j]) / 2.00;
                cout << intersection << "\n";
                if (intersection == int(intersection)) {
                    countIntegerPoints += 1;
                }
            }
        }
        cout << countIntegerPoints << "\n";
    }

}