#include <bits/stdc++.h>

using namespace std;

long long calculate_profit(long long n, long long a, long long b, long long k) {
    long long modified_sum = k * (2 * b - k + 1) / 2;
    long long usual_sum = (n - k) * a;
    return modified_sum + usual_sum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("contest-1978B.in", "r", stdin);
    freopen("contest-1978B.out", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;

    while (test--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long max_profit = 0;
        long long left = 0;
        long long right = min(n, b);

        while (right - left > 2) {
            long long m1 = left + (right - left) / 3;
            long long m2 = right - (right - left) / 3;

            long long profit1 = calculate_profit(n, a, b, m1);
            long long profit2 = calculate_profit(n, a, b, m2);

            if (profit1 < profit2) {
                left = m1;
            } else {
                right = m2;
            }
        }

        for (long long k = left; k <= right; ++k) {
            max_profit = max(max_profit, calculate_profit(n, a, b, k));
        }

        cout << max_profit << "\n";
    }

    return 0;
}
