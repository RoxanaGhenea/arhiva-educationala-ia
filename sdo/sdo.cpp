//https://www.infoarena.ro/problema/sdo

#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int v[3000005];
vector <int> sdo;

int solve(int left, int right, int k) {
    sdo.clear(); 
    int indexPivot;
    int randNumber = rand() % (right - left + 1) + left;
    for (int i = left; i <= right; ++i) {
        if (v[i] <= v[randNumber] and i != randNumber) {
            sdo.push_back(v[i]);
        }
    }
    sdo.push_back(v[randNumber]);
    indexPivot = sdo.size() + left - 1;
    for (int i = left; i <= right; ++i) {
        if (v[i] > v[randNumber]) {
            sdo.push_back(v[i]);
        }
    }
    int j = 0;
    for (int i = left; i <= right; ++i) {
        if (j != sdo.size()) {
            v[i] = sdo[j];
            j += 1;
        }        
    }
    if (k == indexPivot) return v[indexPivot]; 
    if (k < indexPivot) {
        return solve(left, indexPivot - 1, k);
    } else {
        return solve(indexPivot + 1, right, k);
    }    
}

int main()
{
    ifstream fin("sdo.in");
    ofstream fout("sdo.out");
    srand(time(nullptr));

    int n, k; 
    fin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
    }

    solve(1, n, k);
    int ans = v[k];
    fout << ans;
}