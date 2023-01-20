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
}