#include <iostream>
#include <string>
using namespace std;

int main() {
    string number;
    cin >> number;
    for (int i = number.length() - 1; i >= 0; cout << number[i--]);
}
