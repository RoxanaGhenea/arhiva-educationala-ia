//https://codeforces.com/contest/1985/problem/A

#include <bits/stdc++.h>

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1985A.in", "r", stdin);
    freopen("contest-1985A.out", "w", stdout);
    #endif

    int test;
    cin >> test;

    while(test--) {
        string a, b;
        cin >> a >> b;
        swap(a[0], b[0]);
        cout << a << " " << b << "\n";
    }

}