#include <fstream>
using namespace std;

int euclidAlgorithm(int a, int b) {
    int gcd;
    if(a < b) {
        swap(a, b);
    }

    if (b != 0) {
        gcd = a%b;
        return euclidAlgorithm(gcd, b);
    } else {
        gcd = a;
    }
    return gcd; 
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b;
        fin >> a >> b;
        fout << euclidAlgorithm(a, b) << "\n";
    }
}
