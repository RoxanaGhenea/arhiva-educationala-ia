//https://infoarena.ro/problema/submultimi

#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("submultimi.in");
ofstream fout ("submultimi.out");

vector <int> submultime;

void solution(int position, int N, int lastValue) {
    for (int i = lastValue; i <= N; ++i) {
        submultime.push_back(i);
        for (int j = 0; j < submultime.size(); ++j) {
            fout << submultime[j] << " ";
        }
        fout << "\n";
        lastValue += 1;
        solution(position + 1, N, lastValue);
        submultime.pop_back();
    }
}


int main ()
{
    int N;
    fin >> N;
    solution(1, N, 1);
}