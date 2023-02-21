//https://codeforces.com/contest/1253/problem/B

#include <bits/stdc++.h>

using namespace std;
int event[1000005];
map <int, int> fq;
vector <int> eventsPerDay;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1253B.in", "r", stdin);
    freopen("contest-1253B.out", "w", stdout);
    #endif

    int n, countDays = 0, lastPosition = 0, ans = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> event[i];
        fq[event[i]] = 0;
    }

    int sumEventsDay = 0;
    int initialPosition = 1;
    for (int i = 1; i <= n; ++i) {
        fq[event[i]] += 1;
        if (fq[event[i]] > 1) {
            countDays = 0;
            ans = -1;
            break;
        }
        if (event[i] < 0 and fq[-event[i]] == 0) {
            countDays = 0;
            ans = -1;
            break;
        }
        sumEventsDay += event[i];
        if (sumEventsDay == 0) {
            countDays += 1;
            eventsPerDay.push_back(i - lastPosition);
            lastPosition = i;
            for (int j = initialPosition; j <= lastPosition; ++j) {
                fq[event[j]] = 0;
            }
            initialPosition = lastPosition + 1;
        }
        if (sumEventsDay != 0 and i == n) {
            countDays = 0;
            ans = -1;
        }
    }

    if (countDays != 0) {
        cout << countDays << "\n";
        for (int j = 0; j < eventsPerDay.size(); ++j) {
            cout << eventsPerDay[j] << " ";
        }
    } else {
        cout << ans;
    }
}