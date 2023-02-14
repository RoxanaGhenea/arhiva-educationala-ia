//https://www.infoarena.ro/problema/hashuri

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector <int> hashTable[1000000];
int MOD = 999961;

int find(int parameter) {
    int key;
    key = parameter % MOD;
    for (int i = 0; i < hashTable[key].size(); ++i) {
        if (parameter == hashTable[key][i]) {
            return 1;
        }
    }
    return 0;
}

void addParameter(int parameter) {
    int key;
    key = parameter % MOD;
    if (!find(parameter)) {
        hashTable[key].push_back(parameter);
    }
}

void removeParameter(int parameter) {
    int key;
    key = parameter % MOD;
    for (int i = 0; i < hashTable[key].size(); ++i) {
        if (parameter == hashTable[key][i]) {
            swap(hashTable[key].back(), hashTable[key][i]);
            hashTable[key].pop_back();
            break;
        }
    }
}

int main()
{
    ifstream fin("hashuri.in");
    ofstream fout("hashuri.out");

    int N;
    fin >> N;
    for (int i = 1; i <= N; ++i) {
        int operationType, parameter;
        fin >> operationType >> parameter;
        if (operationType == 1) {
            addParameter(parameter);
        } else if (operationType == 2) {
            removeParameter(parameter);
        } else {
            fout << find(parameter);
            fout << "\n";
        }
    }
}