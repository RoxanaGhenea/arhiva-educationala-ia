//https://www.infoarena.ro/problema/rucsac

#include <fstream>

using namespace std;
int weight[10005];
int profit[10005];
long long tableValues[5][10005];

int main()
{
    ifstream fin("rucsac.in");
    ofstream fout("rucsac.out");

    int object, maxWeight;
    long long ans = -100000;

    fin >> object >> maxWeight;

    for (int i = 1; i <= object; ++i) {
        fin >>  weight[i] >> profit[i];
    }
   
    for (int i = 1; i <= object; ++i){
        for (int j = 0; j <= maxWeight; ++j) {
            tableValues[1][j] = tableValues[0][j];
            if (j - weight[i] >= 0) { 
                tableValues[1][j] = max(tableValues[0][j], tableValues[0][j - weight[i]] + profit[i]);
            }
            if (ans <= tableValues[1][j]) {
                ans = tableValues[1][j];
            }
        }
        for (int k = 0; k <= maxWeight; ++k) {
            tableValues[0][k] = tableValues[1][k];
        }
    }
    fout << ans;   
}