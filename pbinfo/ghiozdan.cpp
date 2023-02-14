//https://www.pbinfo.ro/probleme/2131/ghiozdan
#include <fstream>

using namespace std;
int storeLocation[1000005];
int distances[1000005];

bool isSizeOk(int backpackSize, int distances[], int distanceWithoutFood, int n) {
    for (int i = 1; i <= n; ++i) {
        if (distances[i] - backpackSize >= 0) {
            if (distances[i] - backpackSize > distanceWithoutFood) {
                return false;
            } else {
                distanceWithoutFood += backpackSize - distances[i];
            }
        }
    }
    return true;
}

int binarySearch (int left, int right, int distanceWithoutFood, int n) {
    int middle = (left + right) / 2;
    if (left != right) {
        if (isSizeOk(middle, distances, distanceWithoutFood, n) == true) {
            right = middle;
            return binarySearch (left, right, distanceWithoutFood, n);
        } else {
            left = middle + 1;
            return binarySearch (left, right, distanceWithoutFood, n);
        }
    }
    return middle;
}

int main() 
{
    ifstream fin("ghiozdan.in");
    ofstream fout("ghiozdan.out");

    int iceRinkLocation, numberStores, distanceWithoutFood, ans;
    fin >> iceRinkLocation >> numberStores >> distanceWithoutFood;
    for (int i = 1; i <= numberStores; ++i) {
        fin >> storeLocation[i];
    }
    storeLocation[numberStores + 1] = iceRinkLocation;

    for (int j = 1; j <= numberStores; ++j) {
        distances[j] = storeLocation[j] - storeLocation[j - 1];
    }
    
    ans = binarySearch(0, iceRinkLocation, distanceWithoutFood, numberStores + 1);

    fout << ans;
}