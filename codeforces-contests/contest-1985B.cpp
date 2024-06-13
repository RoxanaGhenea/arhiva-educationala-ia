//https://codeforces.com/contest/1985/problem/B

#include <bits/stdc++.h>

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1985B.in", "r", stdin);
    freopen("contest-1985B.out", "w", stdout);
    #endif

    int test;
    cin >> test;

    while(test--) {
        int n, max = -1, quotient, sumMultiples, iMax;
        cin >> n;

        for (int i = 2; i <= n; ++i) {
            quotient = n / i;
            sumMultiples = i * quotient * (quotient + 1) / 2;
            if (max <= sumMultiples) {
                max = sumMultiples;
                iMax = i;
            }
        }
        cout << iMax << "\n";
    }
    
}