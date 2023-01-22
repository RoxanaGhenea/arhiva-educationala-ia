#include <fstream>
#include <vector>
#include <queue>

using namespace std;

bool visited[100005];

vector <int> neighbors[100005];
int distances[100005];
queue <int> bfsQueue;

void bfs(int node) {
    int distanceNode = 0;
    distances[node] = distanceNode;
    bfsQueue.push(node);
    visited[node] = true;
    while (!bfsQueue.empty()) {
        int currentNode = bfsQueue.front();
        bfsQueue.pop();
        
        for (int i = 0; i < neighbors[currentNode].size(); ++i) {
            if (visited[neighbors[currentNode][i]] != true) {
                bfsQueue.push(neighbors[currentNode][i]);
                visited[neighbors[currentNode][i]] = true;
                distances[neighbors[currentNode][i]] = distances[currentNode] + 1;
            }
        }    
    }  
}

int main() 
{
    ifstream fin("bfs.in");
    ofstream fout("bfs.out");
    int n, m, S;
    fin >> n >> m >> S;

    for (int i = 0; i < m; ++i) {
        int node1, node2;
        fin >> node1 >> node2;
        neighbors[node1].push_back(node2);
    }

    for (int i = 1; i <= n; ++i) {
        distances[i] = 0;
    }

    bfs(S);

    for (int i = 1; i <= n; ++i) {
        if (S == i) {
            fout << 0 << " ";
        } else if (distances[i] == 0) {
            fout << -1 << " ";
        } else {
            fout << distances[i] << " ";
        }
    }
}