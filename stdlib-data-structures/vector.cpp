#include <iostream>
#include <vector>

using namespace std;

vector <int> studentScores;

int main()
{
    int students, grade;
    cin >> students;

    for (int i = 1; i <= students; ++i) {
        cin >> grade;
        studentScores.push_back(grade);
    }

    for (auto i = studentScores.begin(); i != studentScores.end(); ++i) {
        cout << *i << " ";
    }
//I expect the below to pop the last element of the vector.
    studentScores.pop_back();

    cout << "\n";
//I expect the below to give me the number of elements currently present in the vector.
    cout << studentScores.size() << "\n";

//I expect the below to resize the vector to store 3 elements. 
    studentScores.resize(3);
    for (int i = 1; i <= studentScores.size(); ++i) {
        cout << studentScores[i] << " ";
    }
}