//https://codeforces.com/contest/1281

#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1281A.in", "r", stdin);
    freopen("contest-1281A.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; ++i) {
        cin >> s;
        if (s[s.size() - 1] == 'o') {
            cout << "FILIPINO" << "\n";
        }
        if (s[s.size() - 1] == 'a') {
            cout << "KOREAN" << "\n";
        }
        if (s[s.size() - 1] == 'u') {
            cout << "JAPANESE" << "\n";
        }
    }

}