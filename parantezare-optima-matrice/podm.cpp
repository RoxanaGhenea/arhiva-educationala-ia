//https://www.infoarena.ro/problema/podm

#include <fstream>

using namespace std;
int sizeMatrix[10005];
long long dp[1000][1000];

int main()
{
    ifstream fin("podm.in");
    ofstream fout("podm.out");

    int n;

    fin >> n;
    for (int i = 1; i <= n + 1; ++i) {
        fin >> sizeMatrix[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = 1000000000000000LL;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min (dp[i][j], dp[i][k] + dp[k + 1][j] + 1LL * sizeMatrix[i] * sizeMatrix[k + 1] * sizeMatrix[j + 1]);
            }
        }
    }
    fout << dp[1][n];


}