#pragma warning(disable: 4996)
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;
//Use a stack to reverse a line of input characters that are read into a string. Your stack should contain the
//characters of the user's string. Use getline() for input – it needs to be part of your C++ tool inventory. 
// Jacob Stewart, CIT-245-Z01, 10/12/2021
int main() {
    int retry;
    string str;

    cout << "This program reverses a string using the STL stack.\n";

    do {
        cout << "Enter your string of less than 80 characters followed by and ENTER.\n";
        getline(cin, str);
        stack <char> newStack;

        for (int i = 0; i < str.length(); i++) {
            newStack.push(str[i]);
        }
        while (!newStack.empty()) {
            cout << newStack.top();
            newStack.pop();
        }

        cout << "\nEnter 1 to try again, Anything else to stop: ";
        cin >> retry;
        cin.ignore(1000, '\n');
    } while (retry == 1);

    system("pause");
    return 0;
}
