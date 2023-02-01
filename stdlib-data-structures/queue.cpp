#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> studentGrades;
    //I expect the below to push 10 grades between 1 and 10 and show at each step the inserted value.
        for (int i = 1; i <= 10; i++) {
        int value = rand() % 10 + 1;
        studentGrades.push(value);
        cout << studentGrades.back() << " ";
    }
    cout << "\n";
    //I expect the below to show first value and pop that value until the queue is empty.
    while (!studentGrades.empty()) {
        cout << studentGrades.front() << " ";
        studentGrades.pop();
    }
    
    cout << "\n";
    //I expect the below to return size 0.
    cout << studentGrades.size();   
}
