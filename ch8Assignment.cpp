#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//Implement a class money.You must have friend functions for I / O that overload << and >> .You must have
//multiple constructors, You must implement a percentage method, +, -, <, >.There is a starting money class in
//your text.
// CHANGES MARKED WITH ***************
// Jacob Stewart, CIT-245-Z01, 9/26/2021
class Money {
public:
	Money();
	Money(double amount);
	Money(int dollars, int cents);
	Money(int dollars);
	double getAmount() const;
	int getDollars() const;
	int getCents() const;
	friend double percentage(const Money& amount, int percent);
	friend const Money operator +(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount1, const Money& amount2);
	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money & amount1, const Money & amount2);
	friend bool operator >(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount);
	friend ostream& operator <<(ostream& outputStream, const Money& amount);
	friend istream& operator >>(istream& inputStream, Money& amount);
private:
	int dollars, cents;

	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
	int round(double number) const;
};

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	Money yourAmount, myAmount(10, 9);
	cout << "Enter an amount of money: ";
	cin >> yourAmount;
	cout << "Your amount is " << yourAmount << endl;
	cout << "My amount is " << myAmount << endl;

	if (yourAmount == myAmount)
		cout << "We have the same amounts.\n";
	else
		cout << "One of us is richer.\n";
	//STUFF I ADDED*************************************************
	if (yourAmount > myAmount)
		cout << "You have more money than me.\n";
	else if (yourAmount < myAmount)
		cout << "I have more money than you.\n";

	int percent = 10;
	double a = percentage(yourAmount, percent);
	cout << percent << "% of your money is about: $" 
		<< a << endl;
	//**************************************************************
	Money ourAmount = yourAmount + myAmount;
	cout << yourAmount << " + " << myAmount
		<< " equals " << ourAmount << endl;

	Money diffAmount = yourAmount - myAmount;
	cout << yourAmount << " - " << myAmount
		<< " equals " << diffAmount << endl;

	return 0;

	system("pause");
	return 1;
}

Money::Money() : dollars(0), cents(0) {};
Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount)) {}
Money::Money(int theDollars) : dollars(theDollars), cents(0) {}

Money::Money(int theDollars, int theCents) {
	if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0)) {
		cout << "Inconsistent money data.\n";
		exit(1);
	}
	dollars = theDollars;
	cents = theCents;
}

double Money::getAmount() const {
	return (dollars + cents * 0.01);
}

int Money::getDollars() const {
	return dollars;
}

int Money::getCents() const {
	return cents;
}

int Money::dollarsPart(double amount) const{
	return static_cast<int>(amount);
}

int Money::centsPart(double amount) const {
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}

int Money::round(double number) const {
	return static_cast<int>(floor(number + 0.5));
}

const Money operator +(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.cents + amount1.dollars * 100;
	int allCents2 = amount2.cents + amount2.dollars * 100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (sumAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
	int allCents1 = amount1.cents + amount1.dollars * 100;
	int allCents2 = amount2.cents + amount2.dollars * 100;
	int diffAllCents = allCents1 - allCents2;
	int absAllCents = abs(diffAllCents);

	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (diffAllCents < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
	return ((amount1.dollars == amount2.dollars)
		&& (amount1.cents == amount2.cents));
}

// STUFF I ADDED**************************************************
double percentage(const Money& amount, int percent) {
	double newAmount = amount.getAmount() * (percent / 100.0);
	newAmount = floor(newAmount * 100 + 0.5);
	newAmount = newAmount / 100;
	return newAmount;
}
bool operator <(const Money& amount1, const Money& amount2) {
	if (amount1.dollars < amount2.dollars)
		return true;
	else if (amount1.dollars > amount2.dollars)
		return false;
	else // if (amount1.dollars == amount2.dollars) 
	{
		if (amount1.cents < amount2.cents)
			return true;
		else
			return false;
	}
}

bool operator >(const Money& amount1, const Money& amount2) {
	if (amount1.dollars > amount2.dollars)
		return true;
	else if (amount1.dollars < amount2.dollars)
		return false;
	else // if (amount1.dollars == amount2.dollars) 
	{
		if (amount1.cents > amount2.cents)
			return true;
		else
			return false;
	}
}
// END OF STUFF I ADDED************************************************
const Money operator -(const Money& amount) {
	return Money(-amount.dollars, -amount.cents);
}

ostream& operator << (ostream& outputStream, const Money& amount) {
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << '$';
	outputStream << absDollars;

	if (absCents >= 10)
		outputStream << '.' << absCents;
	else
		outputStream << '.' << '0' << absCents;

	return outputStream;
}

istream& operator >>(istream& inputStream, Money& amount) {
	char dollarSign;
	inputStream >> dollarSign;
	if (dollarSign != '$') {
		cout << "No dollar sign in Money input.\n";
		exit(1);
	}

	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);

	return inputStream;
}