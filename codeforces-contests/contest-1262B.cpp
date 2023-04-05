//https://codeforces.com/contest/1262/problem/B

#include <bits/stdc++.h>

using namespace std;
int q[100005];
bool visited[100005];
set <int> available;
int permutation[100005];
int maxPrefix[100005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1262B.in", "r", stdin);
    freopen("contest-1262B.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; ++i) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> q[j];
        }
        for (int j = 1; j <= n; ++j) {
            available.insert(j);
        }
        for (int j = 1; j <= n; ++j) {
            if (visited[q[j]] == false) {
                permutation[j] = q[j];
                available.erase(q[j]);
                visited[q[j]] = 1;
            } else {
                int first_value = *available.begin();
                permutation[j] = first_value;
                available.erase(first_value);
                visited[first_value] = 1;
            }
        }

        maxPrefix[1] = permutation[1];
        for (int j = 1; j <= n; ++j) {
            maxPrefix[j] = max(maxPrefix[j - 1], permutation[j]);
        }
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (maxPrefix[j] == q[j]) {
                cnt += 1;
            }
        }
        
        if (cnt == n) {
            for (int k = 1; k <= n; ++k) {
                cout << permutation[k] << " ";
            }
        } else {
            cout << -1;
        }
        cout << "\n";
    
        for (int k = 1; k <= n; ++k) {
            visited[k] = 0;
            permutation[k] = 0;
        }
        available.clear();
    }
}