#include <bits/stdc++.h>

using namespace std;

vector <int> studentScores;

int main()
{
    int grade;
    // For this example students number = 5, grades: 6, 7, 8, 9, 10;

    for (int i = 1; i <= 5; ++i) {
        cin >> grade;
        // The below line will insert the grades in the vector in the following order: 6 7 8 9 10
        studentScores.push_back(grade);
    }
    //Below output I expect to be: 6 7 8 9 10
    for (auto i = studentScores.begin(); i != studentScores.end(); ++i) {
        cout << *i << " ";
    }
    //I expect the below to pop the last element of the vector which is 10.
    studentScores.pop_back();

    cout << "\n";
    //I expect the below to give me the number of elements currently present in the vector, 4.
    cout << studentScores.size() << "\n";

    //I expect the below to resize the vector to store 5 elements. 
    studentScores.resize(5);

    for (int i = 0; i < studentScores.size(); ++i) {
        cout << studentScores[i] << " ";
    }
    cout << "\n";
    //I expect below output: 9 8 7 6
    reverse(studentScores.begin(), studentScores.end());
    for (int i = 0; i < studentScores.size(); ++i) {
        cout << studentScores[i] << " ";
    }
    cout << "\n";
    //I expect below output: 6 7 8 9
    sort(studentScores.begin(), studentScores.end());
    for (int i = 0; i < studentScores.size(); ++i) {
        cout << studentScores[i] << " ";
    }
}