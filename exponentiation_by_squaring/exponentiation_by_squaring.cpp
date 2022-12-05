#include <iostream>
#include <fstream>

using namespace std;

int x = 1999999973;

int exponentiationBySquaring(long long a, long long b) {
    int ans;
    if (b == 0) {
        ans = 1;
    } else if (b % 2 == 0) {
        ans = (exponentiationBySquaring((a * a) % x, b/2)) % x;
    } else {
        ans = (a * exponentiationBySquaring((a * a) % x, (b-1)/2)) % x;
    }
    return ans;
}

int main() 
{
    ifstream fin("lgput.in");
    ofstream fout("lgput.out");
    int n, p;
    fin >> n >> p;
    fout << exponentiationBySquaring(n, p);
}