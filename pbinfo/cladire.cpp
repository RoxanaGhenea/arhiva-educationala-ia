//https://www.pbinfo.ro/probleme/392/cladire

#include <fstream>

using namespace std;

int MOD = 9901;
int ans[1005][1005];

int main()
{
    ifstream fin("cladire.in");
    ofstream fout("cladire.out");

    int n, m;
    fin >> n >> m;

    ans[1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        ans[i][1] = 1;
    }
    for (int i = 1;i <= m; ++i) {
        ans[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            ans[i][j] = (ans[i-1][j] + ans[i][j - 1]) % MOD;
        }
    }
    fout << ans[n][m];
}