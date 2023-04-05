//https://codeforces.com/contest/1245/problem/B
// paper beats rock
// rock beats scissors
// scissors beat paper

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string hand;
vector<char> winningSequence;

int main()
{
    int testCases;

    cin >> testCases;
    for (int j = 1; j <= testCases; ++j) {
        int gamesNo, rock, paper, scissors, wins = 0;
        int bobRock = 0, bobPaper = 0, bobScissors = 0;

        cin >> gamesNo >> rock >> paper >> scissors;
        cin >> hand;
        for (int i = 0; i < gamesNo; ++i) {
            if (hand[i] == 'R') {
                bobRock += 1;
            }
            if (hand[i] == 'P') {
                bobPaper += 1;
            }
            if (hand[i] == 'S') {
                bobScissors += 1;
            }
        }

        for (int i = 0; i < gamesNo; ++i) {
            if (hand[i] == 'R') {
                if (paper != 0) {
                    paper -= 1;
                    winningSequence.push_back('P');
                    wins += 1;
                } else if (rock - bobScissors >= scissors - bobPaper) {
                    rock -= 1;
                    winningSequence.push_back('R');
                } else {
                    scissors -= 1;
                    winningSequence.push_back('S');
                }
                bobRock -= 1;
            } else if (hand[i] == 'P') {
                if (scissors != 0) {
                    scissors -= 1;
                    winningSequence.push_back('S');
                    wins += 1;
                } else if (paper - bobRock >= rock - bobScissors) {
                    paper -= 1;
                    winningSequence.push_back('P');
                } else {
                    rock -= 1;
                    winningSequence.push_back('R');
                }
                bobPaper -= 1;
            } else {
                if (rock != 0) {
                    rock -= 1;
                    winningSequence.push_back('R');
                    wins += 1;
                } else if (scissors - bobPaper >= paper - bobRock) {
                    scissors -= 1;
                    winningSequence.push_back('S');
                } else {
                    paper -= 1;
                    winningSequence.push_back('P');
                }
                bobScissors -= 1;
            }
        }
        if (wins >= (gamesNo + 1) / 2) {
            cout << "YES" << "\n";
            for (int k = 0; k < winningSequence.size(); ++k) {
                cout << winningSequence[k];
            }
            cout << "\n";
        } else {
            cout << "NO" << "\n";
        }
        winningSequence.clear();
    }
}