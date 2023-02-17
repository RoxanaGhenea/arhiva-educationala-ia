//https://infoarena.ro/problema/dijkstra

#include <bits/stdc++.h>

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

vector <pair<int, int>> neighbor[50005];
priority_queue <pair<int, int>> findMinDistance;
int distanceNode[50005];

void dijkstra(int node, int nodesNo) {
    distanceNode[node] = 0;
    findMinDistance.push({- distanceNode[node], node});

    while (!findMinDistance.empty()) {
        int currentNode = findMinDistance.top().second;
        int dist = -findMinDistance.top().first;
        findMinDistance.pop();
        if (dist > distanceNode[currentNode]) continue;
        for (int i = 0; i < neighbor[currentNode].size(); ++i) {
            if (distanceNode[neighbor[currentNode][i].second] <= distanceNode[currentNode] + neighbor[currentNode][i].first) continue;
            distanceNode[neighbor[currentNode][i].second] = distanceNode[currentNode] + neighbor[currentNode][i].first;
            findMinDistance.push({- distanceNode[neighbor[currentNode][i].second], neighbor[currentNode][i].second});
        }
    }
    for (int i = 2; i <= nodesNo; ++i) {
        if (distanceNode[i] == 100000000) {
            distanceNode[i] = 0;
        }
        fout << distanceNode[i] << " ";
    }
}

int main()
{
    int nodesNo, edgesNo;

    fin >> nodesNo >> edgesNo;

    for (int i = 1; i <= nodesNo; ++i) {
        distanceNode[i] = 100000000;
    }

    for (int i = 1; i <= edgesNo; ++i) {
        int xNode, yNode, distanceXToY;
        fin >> xNode >> yNode >> distanceXToY;
        neighbor[xNode].push_back({distanceXToY, yNode});
    }

    dijkstra(1, nodesNo);
}