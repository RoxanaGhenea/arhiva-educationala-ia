//https://www.infoarena.ro/problema/heapuri

#include <fstream>
#include <vector>

using namespace std;

int whereInHeap[200005];
vector <pair<int, int>> heap;

void insertNode(int node, int entryNumber) {
    int fatherPosition;
    heap.push_back({node, entryNumber});
    int nodeCurrentPosition = heap.size() - 1;
    whereInHeap[entryNumber] = nodeCurrentPosition;

    fatherPosition = nodeCurrentPosition / 2;

    while (fatherPosition > 0 and heap[nodeCurrentPosition].first < heap[fatherPosition].first) {
        swap(heap[nodeCurrentPosition], heap[fatherPosition]);
        swap (whereInHeap[heap[nodeCurrentPosition].second], whereInHeap[heap[fatherPosition].second]);
        nodeCurrentPosition = fatherPosition;
        fatherPosition = nodeCurrentPosition / 2;
    }
}

void deleteNode(int entryNumber) {
    int positionInHeap = whereInHeap[entryNumber];
    swap(heap[positionInHeap], heap[heap.size() - 1]);
    swap(whereInHeap[heap[positionInHeap].second], whereInHeap[heap[heap.size() - 1].second]);
    heap.pop_back();

    int fatherPosition = positionInHeap / 2;

    while (fatherPosition > 0 and heap[positionInHeap].first < heap[fatherPosition].first) {
        swap(heap[positionInHeap], heap[fatherPosition]);
        swap(whereInHeap[heap[positionInHeap].second], whereInHeap[heap[fatherPosition].second]);
        positionInHeap = fatherPosition;
        fatherPosition = positionInHeap / 2;
    }

    int nodePosition = positionInHeap;
    int leftChildPosition = nodePosition * 2;
    int rightChildPosition = nodePosition * 2 + 1;

    while((leftChildPosition < heap.size() and heap[nodePosition].first > heap[leftChildPosition].first) or (rightChildPosition < heap.size() and heap[nodePosition].first > heap[rightChildPosition].first)) {
        if (rightChildPosition < heap.size() and heap[leftChildPosition].first >= heap[rightChildPosition].first) {
            swap(heap[nodePosition], heap[rightChildPosition]);
            swap(whereInHeap[heap[nodePosition].second], whereInHeap[heap[rightChildPosition].second]);
            nodePosition = rightChildPosition;
            leftChildPosition = nodePosition * 2;
            rightChildPosition = nodePosition * 2 + 1;
        } else {
            swap(heap[nodePosition], heap[leftChildPosition]);
            swap(whereInHeap[heap[nodePosition].second], whereInHeap[heap[leftChildPosition].second]);
            nodePosition = leftChildPosition;
            leftChildPosition = nodePosition * 2;
            rightChildPosition = nodePosition * 2 + 1;
        }
    }
}

int main()
{
    ifstream fin("heapuri.in");
    ofstream fout ("heapuri.out");

    int n, entryNumber = 1;
    heap.push_back({0, 0});
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        int code;
        fin >> code;
        if (code == 1 or code == 2) {
            int x;
            fin >> x;
            if (code == 1) {
                insertNode(x, entryNumber);
                entryNumber += 1;
            } else {
                deleteNode(x);
            }
        } else {
            fout << heap[1].first << "\n";
        }
    }
}