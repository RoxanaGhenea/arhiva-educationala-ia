//https://infoarena.ro/problema/rmq

#include <fstream>

using namespace std;
int array[100005];
int dp[100005][25];
int lg[100005];

int main()
{
    ifstream fin("rmq.in");
    ofstream fout ("rmq.out");

    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fin >> array[i];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(array[i], array[i + 1]);
    }
    dp[n][0] = array[n];

    lg[1] = 0;
    for (int j = 2; j <= n; ++j) {
        lg[j] = lg[j / 2] + 1;
    }
    int e = lg[n] + 1;
    for (int j = 1; j <= e; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (i + (1 << (j - 1)) <= n)
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    for (int i = 1; i <= m; ++i) {
        int l, r;
        fin >> l >> r;
        int ans;
        int diff = r - l;
        if (diff == 0) {
            ans = array[l];
        } else {
            int logValue  = lg[diff];
            ans = min(dp[l][logValue], dp[r - (1 << logValue)][logValue]);
        }
        fout << ans << "\n";
    }
}