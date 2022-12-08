// https://infoarena.ro/problema/ssm - Problem to be solved

#include <fstream>

using namespace std;
int v[6000005];
int sPV[6000005];

int main() 
{
    ifstream fin("ssm.in");
    ofstream fout("ssm.out");

    int N, sP = 0, sMin = 0, sMax = -100000000, iBeg = 1, iEnd = 0, iBegPrint = 0;

    fin >> N;
    
    for (int i = 1; i <= N; ++i) {
        fin >> v[i];
        sP += v[i];
        sPV[i] = sP;
    }

    for (int i = 1; i <= N; ++i) {
        if (sPV[i] - sMin > sMax) {
            sMax = sPV[i] - sMin;
            iEnd = i;
            iBegPrint = iBeg;
        }
        if (sPV[i] < sMin) {
            sMin = sPV[i];
            iBeg = i + 1;
        }
    }

    fout << sMax << " " << iBegPrint << " " << iEnd;
}