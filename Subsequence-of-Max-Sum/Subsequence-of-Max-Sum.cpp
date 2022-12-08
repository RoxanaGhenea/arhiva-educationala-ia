// https://infoarena.ro/problema/ssm - Problem to be solved

#include <fstream>

using namespace std;
int v[6000005];
int partialSumsVector[6000005];

int main() 
{
    ifstream fin("ssm.in");
    ofstream fout("ssm.out");

    int N, partialSum = 0, minSum = 0, maxSum = -100000000, iBeg = 1, iEnd = 0, iBegPrint = 0;

    fin >> N;
    
    for (int i = 1; i <= N; ++i) {
        fin >> v[i];
        partialSum += v[i];
        partialSumsVector[i] = partialSum;
    }

    for (int i = 1; i <= N; ++i) {
        if (partialSumsVector[i] - minSum > maxSum) {
            maxSum = partialSumsVector[i] - minSum;
            iEnd = i;
            iBegPrint = iBeg;
        }
        if (partialSumsVector[i] < minSum) {
            minSum = partialSumsVector[i];
            iBeg = i + 1;
        }
    }

    fout << maxSum << " " << iBegPrint << " " << iEnd;
}