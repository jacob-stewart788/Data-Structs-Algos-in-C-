#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/6/21
//Write a program that applies the Babylonian square root algorithm.
//The algorithm is :
//1) guess = input / 2
//2) r = input / guess
//3) guess = (guess + r) / 2
//4) go to 2 until done
int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	double guess, square, input, x;

	cout << "Enter a number and I will apply the Babylonian square root"
		<< "\nalgorithm until I am within .001 of the correct answer.\n"
		<< "Enter your number: ";

	cin >> input;

	cout << "\nYou entered " << input;

	guess = input / 2;
	x = input / guess;
	guess = (guess + x) / 2;
	cout << "\nGuessing " << guess;
	square = guess * guess;

	while (square - input > 0.001) {
		x = input / guess;
		guess = (guess + x) / 2;
		cout << "\nGuessing " << guess;
		square = guess * guess;
	}


	cout << "\nFinished!"
		<< "\nThe Babylonian algorithm gives " << guess
		<< "\nChecking: " << guess << " * " << guess << " = " << (guess * guess)
		<< "\n";

	system("pause");
	return 0;
}
