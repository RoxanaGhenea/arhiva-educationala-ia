#include <bits/stdc++.h>

using namespace std;

char prison[1005][1005];
int distances[1005][1005];
queue <pair<int, int>> bfs;
bool bfsVisited[1005][1005];
int dx[] = {0, 0 , 1, -1};
int dy[] = {1, -1, 0, 0};
priority_queue <pair <int, pair <int, int>>> findMax;
bool pqVisited[1005][1005];

int main() 
{
    ifstream fin("barbar.in");
    ofstream fout("barbar.out");

    int row, column;
    pair <int, int> exit;
    pair <int, int> initialPosition;

    fin >> row >> column;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            distances[i][j] = 1000005;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            fin >> prison[i][j];
            if (prison[i][j] == 'D') {
                distances[i][j] = 0;
                bfs.push({i, j});
                bfsVisited[i][j] = true;
            }
            if (prison[i][j] == 'I') {
                initialPosition.first = i;
                initialPosition.second = j;
            }

            if (prison[i][j] == 'O') {
                exit.first = i;
                exit.second = j;
            }
        }
    }

    while (!bfs.empty()) {
        pair <int, int> currentNode = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; ++i) {
            int neighborX = currentNode.first + dx[i];
            int neighborY = currentNode.second + dy[i];
            if (neighborX < 0 || neighborX >= row) continue;
            if (neighborY < 0 || neighborY >= column) continue;
            if (prison[neighborX][neighborY] == '*') continue;
            if (bfsVisited[neighborX][neighborY]) continue;

            bfs.push({neighborX, neighborY});
            bfsVisited[neighborX][neighborY] = true;
            distances[neighborX][neighborY] = distances[currentNode.first][currentNode.second] + 1;
        }
    }

    findMax.push({distances[initialPosition.first][initialPosition.second], {initialPosition.first, initialPosition.second}});
    pqVisited[initialPosition.first][initialPosition.second];
    int ans = 1000005;

    while (!findMax.empty()) {
        pair <int, pair <int, int>> current = findMax.top();
        findMax.pop();
        ans = min(ans, current.first);
        if (current.second == exit) break;

        for (int i = 0; i < 4; ++i) {
            int neighborX = current.second.first + dx[i];
            int neighborY = current.second.second + dy[i];
            if (neighborX < 0 || neighborX >= row) continue;
            if (neighborY < 0 || neighborY >= column) continue;
            if (prison[neighborX][neighborY] == '*') continue;
            if (pqVisited[neighborX][neighborY]) continue;
            findMax.push({distances[neighborX][neighborY], {neighborX, neighborY}});
            pqVisited[neighborX][neighborY] = true;    
        }
    }

    if (pqVisited[exit.first][exit.second]) {
        fout << ans;
    } else {
        fout << - 1;
    }

}