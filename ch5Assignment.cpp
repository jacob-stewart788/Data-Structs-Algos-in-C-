#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/23/2021
//Write a program that generates random numbers between 1 and 10 and fill an array of size
//20 with them.Have your program sort the array then output in order the number of
//occurrences of each random number generated.Use the STL sort function to sort your array.

int main() {
	bool running = true;
	int arr[20];
	do {
		for (int& x : arr) {
			x = rand() % 10 + 1;
		}

		cout << endl;

		sort(arr, arr + 20);
		cout << "Original list sorted:\n";

		for (int i = 0; i < 20; i++) {
			cout << "arr[" << i << "] = " << arr[i] << endl;
		}

		cout << "\nN count:\n";
		int count;
		for (int i = 1; i <= 10; i++) {
			count = 0;
			for (int x : arr) {
				if (x == i) {
					count++;
				}
			}
			cout << i << ": " << count << endl;
		}

		cout << "\nTry Again? (1 = yes, 0 = no): ";
		cin >> running;
		cout << "*********************************************\n";
	} while (running);
	system("pause");
	return 1;
}
