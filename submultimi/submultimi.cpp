//https://infoarena.ro/problema/submultimi

#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("submultimi.in");
ofstream fout ("submultimi.out");

vector <int> submultime;

void solution(int N, int lastValue) {
    if (!submultime.empty()) {
        for (int j = 0; j < submultime.size(); ++j) {
            fout << submultime[j] << " ";
        }
        fout << "\n";
    }
    
    for (int i = lastValue; i <= N; ++i) {
        submultime.push_back(i);
        solution(N, i + 1);
        submultime.pop_back();
    }
}


int main ()
{
    int N;
    fin >> N;
    solution(N, 1);
}