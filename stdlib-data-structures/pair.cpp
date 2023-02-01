#include <iostream>
#include <utility>

using namespace std;

int main()
{
    // define pair
    pair<string, int> playerNetWorth("David Beckam", 670);

    //I expect the below to say: David Beckam (1st variable) is worth $670 (2nd variable) million.
    cout << playerNetWorth.first << " is worth" << " $" << playerNetWorth.second << " million.";
}