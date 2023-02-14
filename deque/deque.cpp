//https://www.infoarena.ro/problema/deque
#include <fstream>
#include <deque>

using namespace std;

deque <pair<int, int>> myDeque;
int array[5000005];

int main()
{
    ifstream fin("deque.in");
    ofstream fout("deque.out");
    int N, K;
    long long sum = 0;
    pair<int, int> value;

    fin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        fin >> array[i];
        value.first = i;
        value.second = array[i];
        while (!myDeque.empty() and array[i] <= myDeque.back().second) {
            myDeque.pop_back();
        }
        myDeque.push_back(value);
        while (!myDeque.empty() and myDeque.front().first <= i - K) {
            myDeque.pop_front();
        }
        if (i >= K) {
            sum += myDeque.front().second;
        }
    }

    fout << sum;
}