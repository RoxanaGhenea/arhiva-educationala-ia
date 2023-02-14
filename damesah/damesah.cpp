//https://infoarena.ro/problema/damesah

#include <fstream>
#include <vector>

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

int board[15][15];
vector <pair<int, int>> chessSolution;
bool visited[15][15];
int cnt;

void solution(int position, int N) {
    if (position == N + 1) {
        for (int i = 0; i < chessSolution.size(); ++i) {
            fout << chessSolution[i].second << " ";
        }
        fout << "\n";
    }
    for (int line = 1; line <= N; ++line) {
        if (visited[line]) continue;
        for (int column = 1; column <= N; ++column) {
            int newLine = line;
            int newColumn = column;

            while (newLine != N + 1 and newColumn != N + 1) {
                newLine += 1;
                newColumn += 1;
                if (visited[newLine][newColumn]) continue;
            }

            while (newLine != N + 1 and newColumn != 0) {
                newLine += 1;
                newColumn -= 1;
                if (visited[newLine][newColumn]) continue;
            }

            while (newLine != 0 and newColumn != 0) {
                newLine -= 1;
                newColumn -= 1;
                if (visited[newLine][newColumn]) continue;
            }

            while (newLine != 0 and newColumn != N + 1) {
                newLine -= 1;
                newColumn += 1;
                if (visited[newLine][newColumn]) continue;
            }
            chessSolution.push_back({line, column});
            visited[line][column] = true;
            solution(position + 1, N);
            chessSolution.pop_back();
        }
    }
}


int main()
{
    int N;
    fin >> N;
    solution(1, N);
}