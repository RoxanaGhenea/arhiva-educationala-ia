// https://infoarena.ro/problema/bellmanford

#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

vector<pair<int, int>> neighbor[50005];
queue<int> bfQueue;
int nodeQueueFq[50005];
int distances[50005];

void bellmanford(int node, int N)
{
    distances[node] = 0;
    bfQueue.push(node);
    nodeQueueFq[node] += 1;

    while (!bfQueue.empty()) {
        int currentNode = bfQueue.front();
        bfQueue.pop();

        for (int i = 0; i < neighbor[currentNode].size(); ++i) {
            if (distances[neighbor[currentNode][i].first] <= distances[currentNode] + neighbor[currentNode][i].second) continue;
            distances[neighbor[currentNode][i].first] = distances[currentNode] + neighbor[currentNode][i].second;
            bfQueue.push(neighbor[currentNode][i].first);

            nodeQueueFq[neighbor[currentNode][i].first] += 1;
            if (nodeQueueFq[neighbor[currentNode][i].first] > N + 1) {
                fout << "Ciclu negativ!";
                return;
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        fout << distances[i] << " ";
    }
}

int main()
{
    int nodesNumber, edgesNumber;

    fin >> nodesNumber >> edgesNumber;

    for (int i = 1; i <= nodesNumber; ++i) {
        nodeQueueFq[i] = 0;
        distances[i] = 1000000000;
    }

    for (int i = 1; i <= edgesNumber; ++i) {
        int xNode, yNode, costXY;
        fin >> xNode >> yNode >> costXY;
        neighbor[xNode].push_back({yNode, costXY});
    }

    bellmanford(1, nodesNumber);
}