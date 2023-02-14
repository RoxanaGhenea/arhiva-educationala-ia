//https://infoarena.ro/problema/combinari

#include <fstream>
#include <vector>

using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

vector <int> combinari;

void solution(int N, int K, int position, int lastValue) {
    if (position == K + 1) {
        for (int i = 0; i < combinari.size(); ++i) {
            fout << combinari[i] << " ";
        }
        fout << "\n";
    }
        
    for (int i = lastValue; i <= N; ++i) {
        combinari.push_back(i);
        solution(N, K, position + 1, i + 1);
        combinari.pop_back();
    }
}

int main()
{
    int N, K;
    fin >> N >> K;
    solution(N, K, 1, 1);

}