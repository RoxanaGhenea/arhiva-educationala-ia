//https://codeforces.com/contest/1262/problem/A

#include <bits/stdc++.h>
using namespace std;
int leftPoint[100005];
int rightPoint[100005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1262A.in", "r", stdin);
    freopen("contest-1262A.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; ++i) {
        int lines, maxLeft = -1, minRight = 1000000000;
        cin >> lines;
        for (int j = 1; j <= lines; ++j) {
            cin >> leftPoint[j] >> rightPoint[j];
        }
        for (int j = 1; j <= lines; ++j) {
            if (minRight >= rightPoint[j]) {
                minRight = rightPoint[j];
            }
            if (maxLeft <= leftPoint[j]) {
                maxLeft = leftPoint[j];
            }
        }
        int diff = maxLeft - minRight;
        int ans = max(0, diff);
        cout << ans << "\n";
    }
}