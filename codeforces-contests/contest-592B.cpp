//https://codeforces.com/contest/1244/problem/B - Solution Accepted

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int n, rightmostPosition = 0, leftmostPosition = 0, ans;
        cin >> n;

        string s;
        cin >> s;

        for (int j = 0; j <= n-1; ++j) {
            if (s[j] == '1') {
                rightmostPosition = j + 1;
            }
        }

        for (int k = 0; k <= n-1; ++k) {
            if (s[k] == '1') {
                leftmostPosition = k + 1;
                break;
            }
        }
    
        if (rightmostPosition == 0) {
            ans = n;
        } else if (n - leftmostPosition + 1 >= rightmostPosition) {
            ans = 2 * (n - leftmostPosition + 1);
        } else {
            ans = 2 * rightmostPosition;
        }
        cout << ans << "\n";  
    }
}