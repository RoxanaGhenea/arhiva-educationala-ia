//https://www.infoarena.ro/problema/aria

#include <fstream>
#include <iomanip>

using namespace std;

long double x[100005];
long double y[100005];

int main()
{
    ifstream fin("aria.in");
    ofstream fout("aria.out");

    int nPoints;
    long double area = 0;

    fin >> nPoints;

    for (int i = 1; i <= nPoints; ++i) {
        fin >> x[i] >> y[i];
    }
    x[nPoints + 1] = x[1];
    y[nPoints + 1] = y[1];

    for (int i = 1; i <= nPoints; ++i) {
        area += (x[i] * y[i + 1] - x[i + 1] * y[i]);
    }

    area = area / 2;

    if (area < 0) {
        area = -area;
    }

    fout << setprecision(5) << fixed << area;
}