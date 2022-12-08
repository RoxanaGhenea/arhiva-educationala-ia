#include <fstream>

using namespace std;

int x = 1999999973;

int exponentiationBySquaring(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return exponentiationBySquaring((1LL * a * a) % x, b/2) % x;
    } else {
        return (1LL * a * exponentiationBySquaring((1LL * a * a) % x, (b-1)/2)) % x;
    }
}

int main() 
{
    ifstream fin("lgput.in");
    ofstream fout("lgput.out");
    int n, p;
    fin >> n >> p;
    fout << exponentiationBySquaring(n, p);
}