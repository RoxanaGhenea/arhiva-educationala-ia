#include<fstream>

using namespace std;

bool not_prime[2000001];

void sieve(int n){
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i <= n; ++i){
        if (not_prime[i] == false){
            for (int j = 2 * i; j <= n; j += i){
                not_prime[j] = true;
            }
        }
    }
}

int count_prime(int n) {
    int cnt = 0;
    for (int i = 2; i <= n; ++i){
        if (not_prime[i] == false){
            cnt += 1;
        }
    }
    return cnt;
}

int main()
{
   ifstream fin("ciur.in");
   ofstream fout("ciur.out");
   int x;
   fin >> x;
   sieve(x);
   fout << count_prime(x);
}