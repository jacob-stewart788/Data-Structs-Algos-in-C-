#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/15/21
//Write a program that uses a function that returns a number between 1 and 6. Use this
//function to simulate the roll of a die.Allow the user to specify the number of trials and then
//tabulate that number of rolls of two dice.The program must allow for repeated simulations.
//Initialize rand() using srand() and time().

int roll();

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);
	int numberOfRolls, oddsFactor;
	bool running = true;
	cout << "Roll two dice and tabulate the results";
	do {
		srand(time(NULL));
		int total = 0;
		int two, three, four, five, six, seven, eight, nine, ten, eleven, twelve;
		two = three = four = five = six = seven = eight = nine = ten = eleven = twelve = 0;
		
		cout << "\nHow many times would you like to roll?: ";
		cin >> numberOfRolls;
		oddsFactor = numberOfRolls / 36;
		for (; numberOfRolls > 0; numberOfRolls--) {
			total = roll() + roll();
			switch (total) {
			case 2:
				two++;
				break;
			case 3:
				three++;
				break;
			case 4:
				four++;
				break;
			case 5:
				five++;
				break;
			case 6:
				six++;
				break;
			case 7:
				seven++;
				break;
			case 8:
				eight++;
				break;
			case 9:
				nine++;
				break;
			case 10:
				ten++;
				break;
			case 11:
				eleven++;
				break;
			case 12:
				twelve++;
				break;
			default:
				cout << "Error: Ending Program\n";
				exit(0);
			}
		}
		cout << "Sum    #Rolled    Odds    %Error\n"																	
			<< " 2:          " << two << "       " << 1 * oddsFactor << "   " << fabs(((two - 1.0 * oddsFactor) / (1.0 * oddsFactor)) * 100) << endl
			<< " 3:          " << three << "       " << 2 * oddsFactor << "   " << fabs(((three - 2.0 * oddsFactor) / (2.0 * oddsFactor)) * 100) << endl
			<< " 4:          " << four << "       " << 3 * oddsFactor << "   " << fabs(((four - 3.0 * oddsFactor) / (3.0 * oddsFactor)) * 100) << endl
			<< " 5:          " << five << "       " << 4 * oddsFactor << "   " << fabs(((five - 4.0 * oddsFactor) / (4.0 * oddsFactor)) * 100) << endl
			<< " 6:          " << six << "       " << 5 * oddsFactor << "   " << fabs(((six - 5.0 * oddsFactor) / (5.0 * oddsFactor)) * 100) << endl
			<< " 7:          " << seven << "       " << 6 * oddsFactor << "   " << fabs(((seven - 6.0 * oddsFactor) / (6.0 * oddsFactor)) * 100) << endl
			<< " 8:          " << eight << "       " << 5 * oddsFactor << "   " << fabs(((eight - 5.0 * oddsFactor) / (5.0 * oddsFactor)) * 100) << endl
			<< " 9:          " << nine << "       " << 4 * oddsFactor << "   " << fabs(((nine - 4.0 * oddsFactor) / (4.0 * oddsFactor)) * 100) << endl
			<< " 10:         " << ten << "       " << 3 * oddsFactor << "   " << fabs(((ten - 3.0 * oddsFactor) / (3.0 * oddsFactor)) * 100) << endl
			<< " 11:         " << eleven << "       " << 2 * oddsFactor << "   " << fabs(((eleven - 2.0 * oddsFactor) / (2.0 * oddsFactor)) * 100) << endl
			<< " 12:         " << twelve << "       " << 1 * oddsFactor << "   " << fabs(((twelve - 1.0 * oddsFactor) / (1.0 * oddsFactor)) * 100) << endl
		<< "\nTry again? (1 = yes, 0 = no): ";
		cin >> running;
	} while (running);
	system("pause");
	return 0;
}

int roll() {
	return rand() % 6 + 1;
}