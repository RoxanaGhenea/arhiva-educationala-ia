//https://codeforces.com/contest/1243/problem/B1

#include <bits/stdc++.h>

using namespace std;
string s;
string t;
vector <char> diff;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1243B1.in", "r", stdin);
    freopen("contest-1243B1.out", "w", stdout);
    #endif

    int testCases;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i) {
        int stringLen;
        cin >> stringLen;
        cin >> s >> t;
        for (int j = 0; j < stringLen; ++j) {
            if (s[j] == t[j]) continue;
            if (s[j] != t[j]) {
                diff.push_back(s[j]);
                diff.push_back(t[j]);
            }
        }
        if (diff.size() == 0) {
            cout << "YES" << "\n";
        } else if (diff.size() == 4 and (diff[0] == diff[2] and diff[1] == diff[3])) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        diff.clear();
    }
}