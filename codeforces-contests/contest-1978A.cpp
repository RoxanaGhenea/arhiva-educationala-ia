#include <bits/stdc++.h>
 
using namespace std;
 
int noPagesInBooks[105];
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1978A.in", "r", stdin);
    freopen("contest-1978A.out", "w", stdout);
    #endif
 
    int test;
    cin >> test;
 
    while (test--) {
        int noBooks, maxPos = 0, maxValue = 0, previousPos, previousMaxValue = 0;
        cin >> noBooks;
 
        for (int i = 1; i <= noBooks; ++i) {
            cin >> noPagesInBooks[i];
        }
 
        for (int i = 1; i <= noBooks; ++i) {
 
            if (maxValue <= noPagesInBooks[i]) {
                previousMaxValue = maxValue;
                previousPos = maxPos;
                maxValue = noPagesInBooks[i];
                maxPos = i;
            }
        }
 
        if (maxPos < noBooks) {
            cout << noPagesInBooks[maxPos] + noPagesInBooks[noBooks] << "\n";
        }
 
        if (maxPos == noBooks) {
            cout << noPagesInBooks[maxPos] + noPagesInBooks[previousPos] << "\n";
        }
 
    }
    
}