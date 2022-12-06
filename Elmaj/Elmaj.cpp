// https://infoarena.ro/problema/elmaj - Problem to be solved

#include <iostream>
#include <fstream>

using namespace std;

int v[1000001];

int guess(int n) {
    int cnt = 1, k = 1;
    for (int i = 2; i <= n; ++i) {
        if (v[k] == v[i]) {
            cnt += 1;
        } else {
            cnt -= 1;
        }
        if (cnt == 0) {
            k = i;
            cnt = 1;
        }
    }
    return v[k];
}

int main()
{
    ifstream fin("elmaj.in");
    ofstream fout("elmaj.out");
    int n, count_guess = 0, el_maj = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
    }

    el_maj = guess(n);

    for (int i = 1; i <= n; ++i) {
        if (el_maj == v[i]) {
            count_guess += 1;
        }
    }
    if (count_guess >= n/2 + 1) {
        fout << el_maj << " " << count_guess;
    } else {
        return -1;
    }
}