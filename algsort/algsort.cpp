//https://www.infoarena.ro/problema/algsort

#include <fstream>
#include <iostream>

using namespace std;
int array[500005];
int v[500005];

void mergeSort(int left, int right) {
    if (left >= right) return;

    int middle = (left + right) / 2;
    mergeSort(left, middle);
    mergeSort(middle + 1, right);

    int leftIndex = left, rightIndex = middle + 1;
    for (int i = left; i <= right; ++i) {
        if (rightIndex > right || (leftIndex <= middle and array[leftIndex] <= array[rightIndex])) {
            v[i] = array[leftIndex];
            leftIndex += 1;
        } else {
            v[i] = array[rightIndex];
            rightIndex += 1;    
        }
    }
    cout << "\n";
    for (int j = left; j <= right; ++j) {
        array[j] = v[j];
    }
}

int main()
{
    ifstream fin("algsort.in");
    ofstream fout("algsort.out");

    int nNumbers;
    fin >> nNumbers;
    for (int i = 1; i <= nNumbers; ++i) {
        fin >> array[i];
    }
    mergeSort(1, nNumbers);
    for (int i = 1; i <= nNumbers; ++i) {
        fout << array[i] << " ";
    }
}