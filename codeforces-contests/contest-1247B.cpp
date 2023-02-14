#include <bits/stdc++.h>

using namespace std;
map <int, int> showFrequency;
int showArray[200005];

int main()
{
    int tests;

    cin >> tests;

    for (int i = 1; i <= tests; ++i) {
        showFrequency.clear();
        int n, k, d, minNumberShows = 200000;
        cin >> n >> k >> d;

        for (int j = 1; j <= n; ++j) {
            cin >> showArray[j];
        }

        for (int j = 1; j <= d; ++j) {
            showFrequency[showArray[j]] += 1;
        }
        if (minNumberShows >= showFrequency.size()) {
            minNumberShows = showFrequency.size();
        }
        for (int j = d + 1; j <= n; ++j) {
            showFrequency[showArray[j]] += 1;
            showFrequency[showArray[j - d]] -= 1;
            if (showFrequency[showArray[j - d]] == 0) {
                showFrequency.erase(showArray[j - d]);
            }
            if (minNumberShows >= showFrequency.size()) {
                minNumberShows = showFrequency.size();
            }
        }
        cout << minNumberShows << "\n";
    }    
}