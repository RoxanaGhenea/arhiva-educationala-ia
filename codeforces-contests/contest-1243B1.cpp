//https://codeforces.com/contest/1243/problem/B1

#include <bits/stdc++.h>

using namespace std;
string s;
string t;
vector <char> sDiff;
vector <char> tDiff;

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
                sDiff.push_back(s[j]);
                tDiff.push_back(t[j]);
            }
        }
        int diff = sDiff.size() + tDiff.size();
        if (diff == 0) {
            cout << "YES" << "\n";
        } else if (diff == 4 and (sDiff[0] == sDiff[1] and tDiff[0] == tDiff[1])) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        sDiff.clear();
        tDiff.clear();
    }
}