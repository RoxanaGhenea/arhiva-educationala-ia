//https://infoarena.ro/problema/damesah

#include <fstream>
#include <vector>

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

vector <int> currentSolution;
bool visited[15];
int cnt = 0;

void solution(int position, int N) {
    if (position == N + 1) {
        cnt += 1;
        if (cnt == 1) {
            for (int i = 0; i < currentSolution.size(); ++i) {
                fout << currentSolution[i] << " ";
            }
            fout << "\n";
        }
    }

    for (int line = 1; line <= N; ++line) {
        int check = 0;
        if (visited[line]) continue;
        for (int queen = 1; queen <= position - 1; ++queen) {
            if (abs(position - queen) == abs(line - currentSolution[queen - 1])) {
                check += 1;
            }
        }
        if (check == 0) {
            currentSolution.push_back(line);
            visited[line] = true;
            solution(position + 1, N);
            visited[line] = false;
            currentSolution.pop_back();
        }   
    }
}


int main()
{
    int N;
    fin >> N;
    solution(1, N);
    fout << cnt;
}