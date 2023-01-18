//https://www.pbinfo.ro/probleme/2131/ghiozdan
#include <iostream>

using namespace std;
int storeLocation[1000005];
int distances[];

bool isSizeOk(int backpackSize, int distances[], int distanceWithoutFood, int n) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (distance[i] - backpackSize >= 0) {
            if (distance[i] - backpackSize >= distanceWithoutFood) {
                return false;
                break;
            } else {
                distanceWithoutFood += backpackSize - distance[i];
                cnt += 1;
            }
        }
    }
    if (cnt == n) {
        return true;
    }
}

int binarySearch (int left, int right) {
    int middle = (left + right) / 2;
    if (left != right) {
        if (isSizeOk(middle) == true) {
            right = middle;
            return binarySearch (left, right);
        } else {
            left = middle + 1;
            return binarySearch (left, right);
        }
    }
    return middle;
}

int main() 
{
    ifstream fin("ghiozdan.in");
    ofstream fout("ghiozdan.out");

    int iceRinkLocation, numberStores, distanceWithoutFood, distance[0] = 0, ans;
    fin >> iceRinkLocation >> numberStores >> totalDistanceWithoutFood;
    for (int i = 1; i <= numberStores; ++i) {
        fin >> storeLocation[i];
    }

    for (int j = 1; j <= numberStores + 1; ++j) {
        distances[j] = storeLocation[j] - storeLocation[j - 1];
    }
    
    ans = binarySearch(0, iceRinkLocation);

    fout << ans;
}