// https://infoarena.ro/problema/kfib - Problem to be solved

#include <fstream>

using namespace std;
int MOD = 666013;

void matrixMultiplication (int matrixX[2][2], int matrixY[2][2]) {
    int product[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                product[i][j] = (int) ((product[i][j] + 1LL * matrixX[i][k] * matrixY[k][j]) % MOD);
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrixX[i][j] = product[i][j];
        }
    }
}

void power (int matrixX[2][2], int k) {
    int result[2][2] = {{1, 0}, {0, 1}};
    while (k) {
        if (k % 2 == 1) {
            matrixMultiplication(result, matrixX);
        }
        matrixMultiplication(matrixX, matrixX);
        k /= 2;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrixX[i][j] = result[i][j];
        }
    }
}

int main()
{
    ifstream fin ("kfib.in");
    ofstream fout ("kfib.out");
    int matrixZ[2][2] = {{0, 1}, {1, 1}};
    int k;
    fin >> k;
    power (matrixZ, k);
    fout << matrixZ[1][0];
    return 0;
}


