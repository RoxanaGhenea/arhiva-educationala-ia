//https://codeforces.com/contest/1255/problem/B

#include <bits/stdc++.h>

using namespace std;
int weight[10005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1255B.in", "r", stdin);
    freopen("contest-1255B.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; ++i) {
        int people, chains, sum = 0;
        cin >> people >> chains;
        for (int f = 1; f <= people; ++f) {
            cin >> weight[f];    
        } 
        if (people == 2) {
            cout << -1 << "\n";
        }
        if (people >= 3 and chains < people) {
            cout << -1 << "\n";
        }
        if (people >= 3 and chains == people) {
            for (int f = 1; f <= people; ++f) {
                sum += weight[f];
            }
            cout << 2 * sum << "\n";
            for (int i = 1; i <= people - 1; ++i) {
                cout << i << " " << i + 1 << "\n";
            }
            cout << people << " " << 1 << "\n";
        }
    }
}