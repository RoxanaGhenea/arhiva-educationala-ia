//https://infoarena.ro/problema/permutari

#include <fstream>
#include <vector>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

vector <int> currentSolution;
bool visited[10];

void backtracking(int position, int N) {
    if (position == N + 1) {
        for (int i = 0; i < N; ++i) {
            fout << currentSolution[i] << " ";
        }
        fout <<"\n";
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[i] == false) {
            currentSolution.push_back(i);
            visited[i] = true;
            backtracking(position + 1, N);
            visited[i] = false;
            currentSolution.pop_back();
        }
    }
}

int main() {

    int N;
    fin >> N;
    backtracking(1, N);
}