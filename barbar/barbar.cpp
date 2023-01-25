//https://www.infoarena.ro/problema/barbar

#include <fstream>
#include <queue>

using namespace std;

char prison[1005][1005];
int distances[1005][1005];
queue <pair<int,int>> bfs;
bool bfsVisited[1005][1005];
bool dfsVisited[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(pair<int,int> sourceNode, int maxDistance, int row, int column) {
    dfsVisited[sourceNode.first][sourceNode.second] = true;
    for (int i = 0; i < 4; ++i) {
        int neighborX, neighborY;
        neighborX = sourceNode.first + dx[i];
        neighborY = sourceNode.second + dy[i];
        if (neighborX < 0 || neighborX >= row) continue;
        if (neighborY < 0 || neighborY >= column) continue;
        if (prison[neighborX][neighborY] == '*') continue;
        if (dfsVisited[neighborX][neighborY] == false && distances[neighborX][neighborY] - maxDistance >= 0) {
            dfsVisited[neighborX][neighborY] = true;
            dfs({neighborX,neighborY}, maxDistance, row, column);
        }
    }
}

int binarySearch(int left, int right, pair<int, int> exitPosition, pair<int,int> sourceNode, int row, int column) {
    int middle = (left + right) / 2;
    if (left != right) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                dfsVisited[i][j] = false;
            }
        }
        dfs(sourceNode, middle + 1, row, column);
        if (dfsVisited[exitPosition.first][exitPosition.second] == true) {
            return binarySearch(middle + 1, right, exitPosition, sourceNode, row, column);
        } else {
            return binarySearch(left, middle, exitPosition, sourceNode, row, column);
        }
    }
    return middle;
}


int main()
{
    ifstream fin("barbar.in");
    ofstream fout("barbar.out");

    int row, column;
    pair <int, int> sourceNode;
    pair <int, int> exit;
    int max = 0;
    fin >> row >> column;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            fin >> prison[i][j];
            distances[i][j] = 1000005;
            if (prison[i][j] == 'D') {
                distances[i][j] = 0;
                bfs.push({i,j});
                bfsVisited[i][j] = true;
            }
            if (prison[i][j]== 'I') {
                sourceNode.first = i;
                sourceNode.second = j;
            }

            if (prison[i][j]== 'O') {
                exit.first = i;
                exit.second = j;
            }
        }
    }

    while (!bfs.empty()) {
        pair<int,int> currentNode = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; ++i) {
            int neighborX, neighborY;
            neighborX = currentNode.first + dx[i];
            neighborY = currentNode.second + dy[i];
            if (neighborX < 0 || neighborX >= row) continue;
            if (neighborY < 0 || neighborY >= column) continue;
            if (prison[neighborX][neighborY] == '*') continue;
            if (bfsVisited[neighborX][neighborY]) continue;

            distances[neighborX][neighborY] = distances[currentNode.first][currentNode.second] + 1;

            bfs.push({neighborX, neighborY});
            bfsVisited[neighborX][neighborY] = true;
        }        
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (prison[i][j] != '*') {
                if (max <= distances[i][j]) {
                    max = distances[i][j];
                }
            }
        }
    }

    int ans = binarySearch(1, distances[sourceNode.first][sourceNode.second], exit, sourceNode, row, column);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            dfsVisited[i][j] = false;
        }
    }

    dfs(sourceNode, ans, row, column);
    if (dfsVisited[exit.first][exit.second]) {
        fout << ans;
    } else {
        fout << -1;
    }
}