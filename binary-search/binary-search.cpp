// https://infoarena.ro/problema/cautbin - Problem to be solved below

#include <fstream>

using namespace std;
int vector[100005];

int binarySearch1 (int valueToFind, int leftIndex, int rightIndex) {
    int middleIndex = (leftIndex + rightIndex) / 2;
    if (leftIndex != rightIndex) {
        if (valueToFind >= vector[middleIndex + 1]) {
            leftIndex = middleIndex + 1;
            return binarySearch1(valueToFind, leftIndex, rightIndex);
        } else {
            rightIndex = middleIndex;
            return binarySearch1(valueToFind, leftIndex, rightIndex);
        }
    }
    return middleIndex;
}

int binarySearch2 (int valueToFind, int leftIndex, int rightIndex) {
    int middleIndex = (leftIndex + rightIndex) / 2;
    if (leftIndex != rightIndex) {
        if (valueToFind <= vector[middleIndex]) {
            rightIndex = middleIndex;
            return binarySearch2(valueToFind, leftIndex, rightIndex);
        } else {
            leftIndex = middleIndex + 1;
            return binarySearch2(valueToFind, leftIndex, rightIndex);
        }
    }
    return middleIndex;
}

int main() 
{
    ifstream fin ("cautbin.in");
    ofstream fout ("cautbin.out");

    int n, m, operationType, valueToFind, ans;
    fin >> n;

    for (int i = 1; i <= n; ++i) {
        fin >> vector[i];
    }

    fin >> m;

    for (int j = 1; j <= m; ++j) {
        fin >> operationType >> valueToFind;
        if (operationType == 0) {
            ans = binarySearch1(valueToFind, 1, n);         
            if (valueToFind != vector[ans]) {
                ans = - 1;
            }
        } else if (operationType == 1) {
            ans = binarySearch1(valueToFind, 1, n);
        } else {
            ans = binarySearch2(valueToFind, 1, n);
        }
        fout << ans << "\n";
    }
}