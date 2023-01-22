#include <fstream>
#include <vector>

using namespace std;

vector <int> nodeNeighborList[100005];

bool visited[100005];

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < nodeNeighborList[node].size(); ++i) {
        if (visited[nodeNeighborList[node][i]] != true) {
            dfs(nodeNeighborList[node][i]);
        }   
    }
}

int main () 
{
    ifstream fin("dfs.in");
    ofstream fout("dfs.out");

    int n, m, cnt = 0;
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int node1, node2;
        fin >> node1 >> node2;

        nodeNeighborList[node1].push_back(node2);
        nodeNeighborList[node2].push_back(node1);
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i] != true) {
            dfs(i);
            cnt += 1;
        }
    }  

    fout << cnt;
}