#include<fstream>

using namespace std;

bool not_prime[2000001];

int sieve(int n){
    not_prime[0] = not_prime[1] = true;
    int cnt = 0;
    for (int i = 2; i <= n; ++i){
        if (not_prime[i] == false){
            cnt += 1;
            for (int j = 2 * i; j <= n; j += i){
                not_prime[j] = true;
            }
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
   fout << sieve(x);
}