#include <fstream>
using namespace std;

int euclidAlgorithm(int a, int b) {
    if(a < b) {
        swap(a, b);
    }

    if (b != 0) {
        return euclidAlgorithm(a % b, b);
    } else {
        return a;
    }
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
