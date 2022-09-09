#pragma warning(disable: 4996)
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Make a program that can write advice to a file. Your program should not require a data file to be present when it
//is run.If a file needs to be created, your program should do so.
// Jacob Stewart, CIT-245-Z01, 10/19/2021

int main() {

    ifstream inStream("advice.txt");

    if (!inStream.fail()) {
        //Second, file exists
        cout << "Found Advice file.\nOld Advice:\n";
        string str;
        getline(inStream, str);
        //inStream.ignore(1000, '\n');
        cout << str << endl
            << "Enter your phrase for the next user:\n";
        ofstream outStream("advice.txt");
        getline(cin, str);
        //cin.ignore(1000, '\n');
        outStream << str;

    }
    else {

        //First, no file
        inStream.close();
        cout << "Could not open Advice file.\nAssumption: first run - creating new file...\n";
        fstream fStream;
        fStream.open("advice.txt", ios::in | ios::out | ios::trunc);
        cout << "Enter your phrase for the next user:\n";
        string str;
        getline(cin, str);
        //cin.ignore(1000, '\n');
        fStream << str;
    }
    system("pause");
    return 0;
}