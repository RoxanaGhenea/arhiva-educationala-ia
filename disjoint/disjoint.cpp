//https://www.infoarena.ro/problema/disjoint

#include <iostream>
#include <fstream>

using namespace std;

int father[100005];
int treeHeight[100005];

int findSet(int node) {
    int root = node;
    while (root != father[root]) {
        root = father[root];
    }
    while (node != root) {
        int nextNode = father[node];
        father[node] = root;
        node = nextNode;
    }
    return root;
}

void unite(int x, int y) {
    if (treeHeight[x] <= treeHeight[y]) {
        father[findSet(x)] = findSet(y);
        treeHeight[x] += 1; 
    } else {
        father[findSet(y)] = findSet(x); 
        treeHeight[y] += 1; 
    }
}


int main()
{
    ifstream fin("disjoint.in");
    ofstream fout("disjoint.out");

    int n, m, code, x, y;
    fin >> n >> m;
    for (int j = 1; j <= n; ++j) {
        father[j] = j;
        treeHeight[j] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        fin >> code >> x >> y;
        if (code == 1) {
            unite(x, y);
        } else if (findSet(x) == findSet(y)) {
            fout << "DA" << "\n";
        } else {
            fout << "NU" << "\n";
        }   
    }
}