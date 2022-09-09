#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
// Template a binary search function. Prove that it works with at least 2 types of data.
// Jacob Stewart, CIT-245-Z01,10/26/2021

template <class T>
void search(T a[], int high, T key, bool& found, int& location) {
    int first = 0;
    int last = high;
    int mid;
    found = false;
    while ((first <= last) && !(found)) {
        mid = (first + last) / 2;
        if (key == a[mid]) {
            found = true;
            location = mid;
        }
        else if (key < a[mid]) {
            last = mid - 1;
        }
        else if (key > a[mid]) {
            first = mid + 1;
        }
    }
}

template <class T>
void print(const T key, const int location, bool& found) {
    if (found) {
        cout << key << " is at index " << location << endl;
    }
    else {
        cout << key << " is not in the array\n";
    }
}

int main() {
    int location = 0;
    bool found;
    int arr[11] = { 0, 1, 3, 5, 6, 7, 9, 10, 11, 13, 15 };
    char arr2[5] = { 'a', 'c', 'd', 'f' , 'g' };

    cout << "Integer array contains:\n";
    for (int i = 0; i < 11; i++)
        cout << arr[i] << " ";

    cout << endl;
    for (int i = -1; i < 16; i++) {
        search(arr, 10, i, found, location);
        print(i, location, found);
    }

    cout << "\nString array contains:\n";
    for (int i = 0; i < 5; i++)
        cout << arr2[i] << " ";

    cout << endl;

    for (int i = 97; i < 106; i++) {
        search(arr2, 4, static_cast<char>(i), found, location);
        print(static_cast<char>(i), location, found);
    }

    system("pause");
    return 1;
}