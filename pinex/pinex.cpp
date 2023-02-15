//https://infoarena.ro/problema/pinex

#include <fstream>
#include <vector>

using namespace std;
ifstream fin("pinex.in");
ofstream fout("pinex.out");

vector <int> primes;
vector <long long> bPrimeFactors;
vector <long long> currentSubset;
vector <pair<long long, int>> productSize;

bool notPrime[1000005];

void sieve(int n) {
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (notPrime[i] == false) {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

void primeFactoring (long long B) {
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] * primes[i] > B) break;
        if (B % primes[i] == 0) {
            bPrimeFactors.push_back(primes[i]);
            while (B % primes[i] == 0) {
                B /= primes[i];
            }
        }
    }
    if (B != 1) {
        bPrimeFactors.push_back(B);
    }
}

void subsets(int N, int lastValue) {
    long long product = 1;
    if (!currentSubset.empty()) {
        for (int i = 0; i < currentSubset.size(); ++i) {
            product *= currentSubset[i];
        }
        productSize.push_back({product, currentSubset.size()});
    }
    for (int i = lastValue; i < N; ++i) {
        currentSubset.push_back(bPrimeFactors[i]);
        subsets(N, i + 1);
        currentSubset.pop_back();
    }
}

int main()
{
    int numberTests;
    sieve(1000000);
    fin >> numberTests;

    for (int i = 1; i <= numberTests; ++i) {
        long long A, B;
        fin >> A >> B;
        long long ans = 0;
        primeFactoring(B);
        subsets(bPrimeFactors.size(), 0);

        for (int j = 0; j < productSize.size(); ++j) {
            if (productSize[j].second % 2 == 0) {
                ans -= A / productSize[j].first;
            } else {
                ans += A / productSize[j].first;
            }
        }
        fout << A - ans << "\n";  

        bPrimeFactors.clear();
        currentSubset.clear();
        productSize.clear();
    }    
}