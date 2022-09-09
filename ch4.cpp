#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/15/21
//Write a program that reduces a fraction to lowest terms.Two functions should be
//implemented.Function gcd should findand return the greatest common denominator and be
//called as g = gcd(num, den); .Function reduce(num, den); should call gcd to provide the lowest
//terms.The lowest terms should be returned via reference in numand den.

int gcd(int num, int den);
int reduce(int& num, int& den);

int main() {
	int num, den;
	bool running = true;
	do {
		cout << "Enter the Numerator and Denominator separated with a space: ";
		cin >> num >> den;
		cout << "The greatest common denominator is: " << reduce(num, den);
		cout << "\nYour reduced fraction is: " << num << "/" << den
			<< "\nTry Again? (1 = yes, 0 = no): ";
		cin >> running;
		cout << endl;
	} while (running);
	system("pause");
	return 1;
}

int gcd(int num, int den) {
	while (den != 0) {
		int temp = den;
		den = num % den;
		num = temp;
	}
	return num;
}

int reduce(int& num, int& den) {
	int d = gcd(num, den);
	num /= d;
	den /= d;
	return d;
}