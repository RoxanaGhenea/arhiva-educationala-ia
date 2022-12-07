// https://infoarena.ro/problema/ssm - Problem to be solved

#include <fstream>

using namespace std;
int v[6000005];
int Spv[6000005];

int main() 
{
    ifstream fin("ssm.in");
    ofstream fout("ssm.out");

    int N, Sp = 0, Smin = 0, Smax = -100000000, Ibeg = 1, Iend = 0, Ibegprint = 0;

    fin >> N;
    
    for (int i = 1; i <= N; ++i) {
        fin >> v[i];
        Sp += v[i];
        Spv[i] = Sp;
    }

    for (int i = 1; i <= N; ++i) {
        if (Spv[i] - Smin > Smax) {
            Smax = Spv[i] - Smin;
            Iend = i;
            Ibegprint = Ibeg;
        }
        if (Spv[i] < Smin) {
            Smin = Spv[i];
            Ibeg = i + 1;
        }
    }

    fout << Smax << " " << Ibegprint << " " << Iend;
}