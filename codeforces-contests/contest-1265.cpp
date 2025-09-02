//https://codeforces.com/contest/1265/problem/A

#include <bits/stdc++.h>

using namespace std;
string s;
const int constant = 294;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1265.in", "r", stdin);
    freopen("contest-1265.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; ++i) {
        cin >> s;
        s[s.size()] = '|';
        if (s.size() == 1 || (s[0] == '?' and s[1] == '?')) {
            s[0] = 'a';
        }
        if (s[0] == '?') {
            if (s[1] == 'a') {
                s[0] = 'c';
            } else {
                s[0] = char(int(s[1] - 1));
            }
        }
        for (int j = 1; j < s.size(); ++j) {
            if (s[j] == '?') {
                if (s[j + 1] == '?' || s[j + 1] == '|') {
                if (s[j - 1] == 'c') {
                    s[j] = 'a';
                } else {
                    s[j] = char(s[j - 1] + 1);
                }
                } else {
                    if (s[j - 1] == s[j + 1]) {
                        if (s[j - 1] == 'c') {
                        s[j] = 'a';
                    } else {
                        s[j] = char(s[j - 1] + 1);
                    }
                    } else {
                        s[j]  = char(constant - int(s[j - 1] + s[j + 1]));
                    }
                }
            }
        }
        
        int cnt = 0;
        for (int j = 1; j < s.size(); ++j) {
            if (s[j] == s[j - 1]) {
                cnt += 1;
            }
        }
        if (cnt > 0) {
            cout << -1 << "\n";
        } else {
            for (int j = 0; j < s.size(); ++j) {
                cout << s[j];
            }
            cout << "\n";
        }
    }
}