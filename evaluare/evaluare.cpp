//https://www.infoarena.ro/problema/evaluare

#include <bits/stdc++.h>

using namespace std;

char s[100005];
int position = 0;

int multiplicationDivision();
int paranthesisCalculation();

int additionSubtraction() {
    int result = multiplicationDivision();
    while (s[position] == '+' or s[position] == '-') {
        if (s[position] == '+'){
            position += 1;
            result += multiplicationDivision();
        } else {
            position += 1;
            result -= multiplicationDivision();
        }
    }
    return result;
}

int multiplicationDivision() {
    int result = paranthesisCalculation();
    while (s[position] == '*' or s[position] == '/') {
        if (s[position] == '*') {
            position += 1;
            result *= paranthesisCalculation();            
        } else {
            position += 1;
            result /= paranthesisCalculation();    
        }
    }
    return result;
}

int paranthesisCalculation() {
    int result = 0;
    if (s[position] == '(') {
        position += 1;
        result = additionSubtraction();
        position += 1;
    } else {
        while (s[position] >= '0' and s[position] <= '9') {
            result = result * 10 + (s[position] - '0');
            position += 1;
        }
    }
    return result;
}

int main()
{
    ifstream fin("evaluare.in");
    ofstream fout("evaluare.out");
    fin.getline(s, 100005);

    fout << additionSubtraction();
}