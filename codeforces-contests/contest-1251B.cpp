//https://codeforces.com/contest/1251/problem/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tests;
    cin >> tests;

    for (int i = 1; i <= tests; ++i) {
        int numberStrings, countOnes = 0, countZeroes = 0, countEven = 0;
        string s;
        cin >> numberStrings;

        for (int j = 1; j <= numberStrings; ++j) {
            cin >> s;
            for (int k = 0; k < s.size(); ++k) {
                if (s[k] == '0') {
                    countZeroes += 1;
                } else {
                    countOnes += 1;
                }
            }
            if (s.size() % 2 == 0) {
                    countEven += 1;
            }
        }
        if ((countZeroes % 2 != 0) && (countOnes % 2 != 0) && (countEven == numberStrings)) {
            cout << numberStrings - 1 << "\n";
        } else {
            cout << numberStrings << "\n";
        }
    }
}