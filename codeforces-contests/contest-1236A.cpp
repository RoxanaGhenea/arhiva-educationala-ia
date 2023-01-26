//https://codeforces.com/contest/1236/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int test;
    cin >> test;

    for (int i = 1; i <= test; ++i) {
        int heap1, heap2, heap3, numberStones = 0;

        cin >> heap1 >> heap2 >> heap3;
        
        numberStones = 3 * min(heap2, heap3 / 2);
        heap2 -= min(heap2, heap3 / 2);
        numberStones += 3 * min (heap1, heap2 / 2);
        
        cout << numberStones << "\n";
    }
}