//https://codeforces.com/contest/1243/problem/A

#include <bits/stdc++.h>
#include <stdio.h>


using namespace std;

vector <int> planks;
vector <int> maxSquare;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("contest-1243A.in", "r", stdin);
    freopen("contest-1243A.out", "w", stdout);
    #endif

    int testCases;
    cin >> testCases;

    for (int i = 1; i <= testCases; ++i) {
        int planksNumber, plankHeight;
        cin >> planksNumber;

        for (int j = 1; j <= planksNumber; ++j) {
            cin >> plankHeight;
            planks.push_back(plankHeight);
        }
        sort(planks.begin(), planks.end());

        int previousPlank = planks.back();
        int sideLength = 0;

        while (!planks.empty()) {
            if (planks.back() == previousPlank and sideLength != planksNumber) {
                planks.pop_back();
                sideLength += 1;
            } else {
                maxSquare.push_back(min(sideLength, previousPlank));
                previousPlank = planks.back();
            } 
            if (sideLength == planksNumber) {
                maxSquare.push_back(min(sideLength, previousPlank));
            }
        }
        int max = - 1000000;
        for (int j = 0; j < maxSquare.size(); ++j) {
            if (max <= maxSquare[j]) {
                max = maxSquare[j];
            }
        }
        cout << max << "\n";
        maxSquare.clear();
        planks.clear();
    }
}