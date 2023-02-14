//https://codeforces.com/contest/1238/problem/B
#include <bits/stdc++.h>

using namespace std;

int initialPositions[100005];
deque <int> game;
int main ()
{
    int query;
    cin >> query;

    for (int i = 1; i <= query; ++i) {
        int numEnemies, distanceShifted, numberStrikes = 0, strikePoint, offset = 0;
        cin >> numEnemies >> distanceShifted;
        for (int j = 1; j <= numEnemies; ++j) {
            cin >> initialPositions[j];
        }

        sort(initialPositions + 1, initialPositions + numEnemies + 1);

        for (int j = 1; j <= numEnemies; ++j) {
            game.push_front(initialPositions[j]);
        }

        while (!game.empty()) {
            strikePoint = game.front();
            numberStrikes += 1;
            offset += distanceShifted;

            while (!game.empty() and game.front() == strikePoint) {
                game.pop_front();    
            }
            while (!game.empty() and game.back() - offset <= 0) {
                game.pop_back();
            }
        }
        cout << numberStrikes << "\n";
    }  
}