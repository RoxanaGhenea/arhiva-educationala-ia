//https://codeforces.com/contest/1248/problem/B
#include <bits/stdc++.h>

using namespace std;
int sticksLen[100005];

int main() 
{
    int numberSticks;
    long long ans, length = 0, height = 0;
    cin >> numberSticks;

    for (int i = 1; i <= numberSticks; ++i) {
        cin >> sticksLen[i];
    }

    sort(sticksLen + 1, sticksLen + numberSticks + 1);
    if (numberSticks % 2 != 0) {
        length += sticksLen[numberSticks / 2 + 1];
    }

    for (int i = 1; i <= numberSticks / 2; ++i) {
        height += sticksLen[i];
        length += sticksLen[numberSticks - i + 1];
    }

    ans = height * height + length * length;

    cout << ans;
    
}