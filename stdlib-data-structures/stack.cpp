#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> scores;
    for (int i = 1; i <= 25; ++i) {
        /* Below will insert 25 scores between 1 and 100 in the stack.
        It will give every value that was inserted in the stack from the first to the last. */
        int value = random() % 100 + 1;
        scores.push(value);
        cout << scores.top() << " ";
    }

    cout << "\n";
    //Expect to give size of 25.
    cout << scores.size() << "\n";

    while (!scores.empty()) {
        /* Below will record the last element, and the method pop will delete the last element
        from the stack, cout will give the element that was deleted, this will continue until
        the stack will be empty. */
        int deletedElement = scores.top();
        scores.pop();
        cout << deletedElement << " ";
    }
}
