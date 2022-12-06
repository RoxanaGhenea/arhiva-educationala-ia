// https://infoarena.ro/problema/kfib - Problem to be solved

#include <iostream>
#include <fstream>

using namespace std;
int MOD = 666013;

void matrixMultiplication(int X[2][2], int Y[2][2]) {
    int product[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                product[i][j] = (int) ((product[i][j] + 1LL * X[i][k] * Y[k][j]) % MOD);
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            X[i][j] = product[i][j];
        }
    }
}

void lg(int X[2][2], int k) {
    int result[2][2] = {{1, 0}, {0, 1}};
    while (k) {
        if (k % 2 == 1) {
            matrixMultiplication(result, X);
        }
        matrixMultiplication(X, X);
        k /= 2;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            X[i][j] = result[i][j];
        }
    }
}

int main()
{
    ifstream fin ("kfib.in");
    ofstream fout ("kfib.out");
    int Z[2][2] = {{0, 1}, {1, 1}};
    int k;
    fin >> k;
    lg(Z, k);
    fout << Z[1][0];
    return 0;
}


