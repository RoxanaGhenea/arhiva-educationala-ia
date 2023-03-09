//https://codeforces.com/contest/1278/problem/A

#include <bits/stdc++.h>

using namespace std;
string p;
string h;
string compare;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1278A.in", "r", stdin);
    freopen("contest-1278A.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; ++i) {
        int ans = 0;
        cin >> p >> h;
        sort(p.begin(), p.end());

        for (int j = p.size() - 1; j < h.size(); ++j) {
            int cnt = 0;
            compare = h.substr(j - p.size() + 1, p.size());
            sort(compare.begin(), compare.end());
            for (int k = 0; k < p.size(); ++k) {
                if (p[k] == compare[k]) {
                    cnt += 1;
                }
            }
            if (cnt == p.size()) {
                ans += 1;
            }   
        } 
        if (ans > 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}