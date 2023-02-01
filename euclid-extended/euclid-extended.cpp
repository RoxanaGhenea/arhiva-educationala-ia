#include <fstream>
#include <iostream>

using namespace std;

void euclidExtended(long long a, long long b, long long &gcd, long long &x, long long &y) {
    if (b == 0) {
        gcd = a;
        x = 1;
        y = 0;
    } else {
        euclidExtended(b, a % b, gcd, x, y);
        long long xNew = y;
        long long yNew = x - (a / b) * y;
        x = xNew;
        y = yNew;
        cout << x << " " << y << " " << gcd << "\n";
    }   
}

int main()
{
    ifstream fin("euclid3.in");
    ofstream fout("euclid3.out");

    int test;
    fin >> test;

    for (int i = 1; i <= test; ++i) {
        long long a, b, c, d, x, y;
        fin >> a >> b >> c;

        euclidExtended(a, b, d, x, y);
        if (c % d != 0) {
            fout << "0" << " " << "0" << "\n";
        } else {
            fout << x * (c / d) << " " << y * (c / d) << "\n";
        }
    }
}