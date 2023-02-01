//https://codeforces.com/contest/1236/problem/B
#include <bits/stdc++.h>

using namespace std;
int MOD = 1000000007;

int power (int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return power((1LL * a * a) % MOD, b / 2) % MOD;
    } else {
        return (1LL * a * power((1LL * a * a) % MOD, (b - 1) / 2)) % MOD;
    }
}

int main() 
{
    int numberKindsGift, numberBoxes;
    cin >> numberKindsGift >> numberBoxes;
    int ansPart1, ans;
    
    ansPart1 = power (2, numberBoxes) - 1;

    ans = power (ansPart1, numberKindsGift);

    cout << ans;    
}