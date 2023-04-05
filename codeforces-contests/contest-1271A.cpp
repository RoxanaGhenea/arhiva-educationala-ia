//https://codeforces.com/contest/1271/problem/A

#include <bits/stdc++.h>

using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1271A.in", "r", stdin);
    freopen("contest-1271A.out", "w", stdout);
    #endif

    int ties, scarves, vests, jackets, costOne, costTwo, cost = 0;

    cin >> ties >> scarves >> vests >> jackets >> costOne >> costTwo;
    
    if (costOne >= costTwo) {
        int minItem = min(scarves, vests);
        minItem = min(minItem, jackets - min(ties, jackets));
        cost = min(ties, jackets) * costOne + minItem * costTwo;
    }

    if (costTwo > costOne) {
        int minItem = min(scarves, vests);
        minItem = min(minItem, jackets);
        cost = minItem * costTwo + min(ties, jackets - minItem) * costOne;
    } 
    cout << cost;    
}