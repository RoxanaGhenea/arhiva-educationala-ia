//https://www.infoarena.ro/problema/ssnd

#include <fstream>
#include <vector>

using namespace std;
bool notPrime[1000005];
vector <int> primes;
int MOD = 9973;

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


int main ()
{
    ifstream fin("ssnd.in");
    ofstream fout("ssnd.out");

    int test;
    fin >> test;
    sieve(1000000);

    for (int i = 1; i <= test; ++i) {
        long long n, sumPrimeDivisors = 1, numberPrimeDivisors = 1;
        fin >> n;

        long long value = n;
        for (int i = 0; i < primes.size(); ++i) {
            long long countCurrentPrime = 0, currentPrimeSum = 1, powerCurrentPrime = 1;
            if (primes[i] * primes[i] > n) {
                break;
            }
            while (n % primes[i] == 0) {
                value = value / primes[i];
                n = n / primes[i];
                countCurrentPrime += 1;
                powerCurrentPrime = (powerCurrentPrime * primes[i]) % MOD ;
                currentPrimeSum = (currentPrimeSum + powerCurrentPrime) % MOD;
            }
            numberPrimeDivisors *= (1 + countCurrentPrime);
            sumPrimeDivisors = (sumPrimeDivisors * currentPrimeSum) % MOD;
        }
        if (value > 1) {
            numberPrimeDivisors *= 2;
            sumPrimeDivisors = (sumPrimeDivisors * (1 + value)) % MOD;
        }
        fout << numberPrimeDivisors % MOD << " " << sumPrimeDivisors << "\n";
    }
}