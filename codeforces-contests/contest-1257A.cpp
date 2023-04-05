//https://codeforces.com/contest/1257/problem/A

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1257A.in", "r", stdin);
    freopen("contest-1257A.out", "w", stdout);
    #endif

    int testCases;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i) {
        int studentCount, swaps, student1, student2;
        cin >> studentCount >> swaps >> student1 >> student2;
        int maxDistance = swaps + abs(student1 - student2);

        if (maxDistance >= studentCount) {
            cout << studentCount - 1 << "\n";
        }
        if (maxDistance < studentCount) {
            cout << maxDistance << "\n";
        }
    }
}