#include <fstream>
#include <vector>

using namespace std;
int a[1030];
int b[1030];
int result[1030][1030];
vector <int> subsequence;

int main() 
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int sizeA, sizeB;
    fin >> sizeA >> sizeB;

    for (int i = 1; i <= sizeA; ++i) {
        fin >> a[i];
    }

    for (int j = 1; j <= sizeB; ++j) {
        fin >> b[j];
    }

    for (int j = 0; j <= sizeA; ++j) {
        result[0][j] = 0;
    }

    for (int i = 0; i <= sizeB; ++i) {
        result[i][0] = 0;
    }

    for (int i = 1; i <= sizeA; ++i) {
        for (int j = 1; j <= sizeB; ++j) {
            result[i][j] = result[i-1][j-1] + (a[i] == b[j]);
            result[i][j] = max(result[i][j], result[i - 1][j]);
            result[i][j] = max(result[i][j], result[i][j - 1]);
        }
    }

    int i = sizeA, j = sizeB;
    while(j != 0 && i != 0) {
        if (a[i] == b[j]) {
            subsequence.push_back(a[i]);
            i -= 1;
            j -= 1;
            continue;
        }
        if (result[i - 1][j] >= result[i][j - 1]) {
            i -= 1;
            continue;
        }
        j -= 1;
    }

    fout << result[sizeA][sizeB] << "\n";
    while (!subsequence.empty()) {
        fout << subsequence.back() << " ";
        subsequence.pop_back();
    }

}