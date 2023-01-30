#include <iostream>
#include <string>
#include <map>

using namespace std;
map <string, int> cityTemperature;

int main()
{
    string city[] = {"Paris", "London", "Berlin", "Zurich", "Bruge"};
    int temperature[] = {10, 5, 2, -4, 3};
    for (int i = 0; i < 5; ++i) {
        cityTemperature[city[i]] = temperature[i];
    }

    cityTemperature["Manchester"] = 1;
    
    for (auto x : cityTemperature) {
        cout << x.first << " " << x.second << '\n';
    }

    cout << cityTemperature.size() << "\n";

    cityTemperature.erase("Berlin");

    for (auto x : cityTemperature) {
        cout << x.first << " " << x.second << '\n';
    }
    
    cout << cityTemperature.count("Rome") << " " << cityTemperature.count("Paris") << "\n";
    
    cityTemperature.clear();

    cout << cityTemperature.size();

    cout << "\n";

    map <int, int> myMap;
    myMap[5] = 10;
    myMap[2] = 4;
    cout << myMap.size() << "\n";
    if (myMap.count(3) == 0) {
        cout << "3 is not in map" <<"\n";
    }
    for (auto x: myMap) {
        cout << x.first << " ";
    }
    cout << "\n";

    cout << myMap.size() << "\n";

    //The below does not only verify if value 3 is in the map but it also creates a key pair 3 -> 0
    if (myMap[3] == 0) {
        cout << "3 is not in map" << "\n";
    }
    cout << myMap.size() << "\n";

    for (auto x: myMap) {
        cout << x.first << " " << x.second << "\n";
    }
}