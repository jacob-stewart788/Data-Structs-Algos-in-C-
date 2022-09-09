#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
//Research and implement the towers of Hanoi. Use a recursive rather than iterative solution
// Jacob Stewart, CIT-245-Z01, 10/18/2021
void solve(int n, string a, string b, string c, int &count);
int main() {

	int plates, moves = 0;
	cout << "How many plates?:";
	cin >> plates;
	cout << "source: 1, temporary: 2, target: 3\n";
	solve(plates, "1", "3", "2", moves);
	cout << "Moves: " << moves << endl
		<< "2 to the power of " << plates << ": " << pow(2, plates) << endl;
	system("pause");
	return 1;
}

void solve(int n, string a, string c, string b, int &count) {
	if (n != 1) {
		solve(n - 1, a, b, c, count);
		cout << a << " -> " << c << endl;
		count++;
		solve(n - 1, b, c, a, count);

	}
	else {
		cout << a << " -> " + c << endl;
		count++;
	}
}
