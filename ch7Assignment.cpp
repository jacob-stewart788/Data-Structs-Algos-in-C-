#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/25/2021
//Create a counter.The default constructor should set the count to zero.The overloaded constructor should
//initialize to any integer.Provide a display(), inc() and dec() method.Inc does ++ dec does – – on the private
//count variable.Use private:and public: where they should be used.
//	Write a demo program that initializes one counter to 0 and the other to 200. Increment the first counter by
//	85 and decrement the second counter by 242. Use a for loop to incrementand decrement.
//	Use a static variable to keep track of the total number of incsand decs.Keep in mind that after you declare a
//	static variable in a class, you must declare it outside the classand use the scope resolution operator.
class Counter {
private:
	int x;
	static int count;
public:

	Counter() { x = 0; };
	Counter(int a) { x = a; };

	void inc() { x++; count++; };
	void dec() { x--; count++; };
	void display() { cout << "Current count: " << x << endl 
		<< "Total increments and decrements: " << count << endl; };
};

int Counter::count = 0;

int main() {
	Counter first, second(200);

	cout << "First Counter (Created with default constructor)\n";
	first.display();
	
	cout << "Second Counter (Created with second(200))\n";
	second.display();

	for (int i = 0; i < 85; i++) 
		first.inc();

	cout << "First counter after 85 increments\n";
	first.display();

	for (int i = 0; i < 242; i++)
		second.dec();

	cout << "Second counter after 242 decrements\n";
	second.display();

	system("pause");
	return 1;
}