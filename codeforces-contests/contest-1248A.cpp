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
        int n,m, oddP = 0, evenP = 0, oddQ = 0, evenQ = 0;
        long long countIntegerPoints;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> p[j];
            if (p[j] % 2 == 0) {
                evenP += 1;
            } else {
                oddP += 1;
            }
        }
        cin >> m;
        for (int k = 1; k <= m; ++k) {
            cin >> q[k];
            if (q[k] % 2 == 0) {
                evenQ += 1;
            } else {
                oddQ += 1;
            }
        }

        countIntegerPoints = 1LL * oddP * oddQ + 1LL * evenP * evenQ;

        cout << countIntegerPoints << "\n";
    }
}