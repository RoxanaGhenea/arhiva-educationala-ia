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
        while (heap2 != 0 & heap3 >= 2) {
            numberStones += 3;
            heap2 -= 1;
            heap3 -= 2;
        }
        while (heap1 != 0 & heap2 >= 2) {
            numberStones += 3;
            heap1 -= 1;
            heap2 -= 2;
        }
        cout << numberStones << "\n";
    }
}