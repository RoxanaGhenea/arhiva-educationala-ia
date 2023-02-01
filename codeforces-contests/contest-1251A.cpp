//https://codeforces.com/contest/1251/problem/A
#include <bits/stdc++.h>

using namespace std;
bool ok[123];

int main() 
{
    int tests;
    cin >> tests; 

    for (int i = 1; i <= tests; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == s[j + 1]) {
                j += 1;
            } else {
                ok[s[j]] = true;
            }
        }
        
        for (int i = 'a'; i <= 'z'; ++i) {
            if (ok[i] == true) {
                cout << char(i);
            }
        }
        for (int i = 'a'; i <= 'z'; ++i) {
            ok[i] = false;
        }
        cout << "\n";
    }
}