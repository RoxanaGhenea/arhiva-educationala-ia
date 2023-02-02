//https://www.infoarena.ro/problema/radixsort

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int buckets[100005];
int auxiliary[10000005];
int sorted[10000005];

void radix(int n) {
    int x = 100000;
    for (int i = 1; i <= n; ++i) {
        buckets[sorted[i] % x] += 1;
    }
    for (int i = 1; i < x; ++i) {
        buckets[i] += buckets[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        auxiliary[buckets[sorted[i] % x]] = sorted[i];
        buckets[sorted[i] % x] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        sorted[i] = auxiliary[i];
    }
    for (int i = 1; i < x; ++i) {
        buckets[i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        buckets[sorted[i] / x] += 1;
    }
    for (int i = 1; i < x; ++i) {
        buckets[i] += buckets[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        auxiliary[buckets[sorted[i] / x]] = sorted[i];
        buckets[sorted[i] / x] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        sorted[i] = auxiliary[i];
    }       
}

int main()
{
    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");

    int N, A, B, C;
    fin >> N >> A >> B >> C;
    sorted[1] = B;

    for (int i = 2; i <= N; ++i) {
        sorted[i] = (1LL * A * sorted[i - 1] + B) % C;
    }

    radix(N);
    for (int i = 1; i <= N; i += 10) {
        fout << sorted[i] << " ";
    }
}