//https://codeforces.com/contest/1263/problem/B

#include <bits/stdc++.h>

using namespace std;
vector <string> card;
string pin;
map <string, int> fq;
vector<string> pins;
int visited[10];


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1263B.in", "r", stdin);
    freopen("contest-1263B.out", "w", stdout);
    #endif

    int testCase;
    cin >> testCase;

    for (int i = 1; i <= testCase; ++i) {
        int cardNumber;
        int ans = 0;
        cin >> cardNumber;

        for (int j = 0; j < cardNumber; ++j) {
            cin >> pin;
            pins.push_back(pin);
            visited[pin[0] - '0'] += 1;
        }
        
        for (int j = 0; j < cardNumber; ++j) {
            pin = pins[j];
            int firstUnusedDigit = 0;
            for (int k = 0; k < 10; ++k) {
                if (visited[k]) continue;
                firstUnusedDigit = k;
                break;
            }
            if (fq.count(pin)) {
                ans += 1;
                pin[0] = (firstUnusedDigit + '0');
            }
            fq[pin] += 1;
            visited[pin[0] - '0'] += 1;
            card.push_back(pin);
        }
        cout << ans << '\n';
        for (auto x : card) {
            cout << x << '\n';
        }
        fq.clear();
        card.clear();
        pins.clear();
        for (int j = 0; j < 10; ++j) visited[j] = 0;
    }
}