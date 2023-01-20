#include <bits/stdc++.h>

using namespace std;
deque <int> studentGrades;

int main () 
{
    for (int i = 5; i <= 10; ++i) {
        studentGrades.push_back(i);
    }
    //Output expected: 5, 6, 7, 8, 9, 10
    for (int j : studentGrades) {
        cout << j << " ";
    }
    cout << "\n";

    for (int i = 5; i <= 10; ++i) {
        studentGrades.push_front(i);
    }
    //Output expected: 10, 9, 8, 7, 6, 5, 5, 6, 7, 8, 9, 10
    for (int j : studentGrades) {
        cout << j << " ";
    }
    cout << "\n";

    while (studentGrades.size() > 4) {
        studentGrades.pop_back();
        studentGrades.pop_front();
    }
    //Output expected: 6 5 5 6
    for (int j : studentGrades) {
        cout << j << " ";
    }

    cout << "\n";
    //While dstudentGrades is not empty pops element from the back.
    while (!studentGrades.empty()) {
        studentGrades.pop_back();
    }

    for (int i = 5; i <= 10; ++i) {
        studentGrades.push_front(i);
    }
    //Clears deque.
    studentGrades.clear();

    for (int i = 5; i <= 10; ++i) {
        studentGrades.push_front(i);
    }
    //Expected output: 6
    cout << studentGrades.at(4);
        
}