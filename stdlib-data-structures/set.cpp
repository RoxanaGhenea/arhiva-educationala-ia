#include <iostream>
#include <set>

using namespace std;
set <int> mySet;

int main() 
{
    for (int i = 0; i <= 100; i += 10) {
        mySet.insert(i);
    }
    //Output expected: 0 10 20 30 40 50 60 70 80 90 100
    for (auto x: mySet) {
        cout << x << " ";
    }
    cout << "\n";


    //Erases value 50 from the set
    mySet.erase(50);

    //Output expected: 0 10 20 30 40 60 70 80 90 100
    for (auto x: mySet) {
        cout << x << " ";
    }
    cout << "\n";

    if (mySet.find(70) != mySet.end()) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    
    if (mySet.find(101) != mySet.end()) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    mySet.insert(1);
    for (auto x: mySet) {
        cout << x << " ";
    }

    //Output expected: 0 1 10 20
    mySet.erase(mySet.find(30), mySet.end());
    cout << "\n";
    for (auto x: mySet) {
        cout << x << " ";
    }
    //Output expected: 4
    cout << "\n" << mySet.size();
    mySet.clear();
    //Output expected: 0
    cout << "\n" << mySet.size();
}