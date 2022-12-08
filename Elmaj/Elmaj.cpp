// https://infoarena.ro/problema/elmaj - Problem to be solved

#include <fstream>

using namespace std;

int v[1000001];

int guess(int n) {
    int count = 1, k = 1;
    for (int i = 2; i <= n; ++i) {
        if (v[k] == v[i]) {
            count += 1;
        } else {
            count -= 1;
        }
        if (count == 0) {
            k = i;
            count = 1;
        }
    }
    return v[k];
}

int main()
{
    ifstream fin("elmaj.in");
    ofstream fout("elmaj.out");
    int n, countGuess = 0, mostFrequent = 0;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
    }

    mostFrequent = guess(n);

    for (int i = 1; i <= n; ++i) {
        if (mostFrequent == v[i]) {
            countGuess += 1;
        }
    }
    if (countGuess >= n/2 + 1) {
        fout << mostFrequent << " " << countGuess;
    } else {
        return -1;
    }
}