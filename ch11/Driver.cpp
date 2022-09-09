#pragma warning(disable: 4996)
#include <iostream>
#include<stdlib.h>
#include "f.h"
#include "g.h"
using namespace std;
//Create 5 files. Driver.cpp, f.h, f.cpp, g.h, g.cpp. f and g should implement a function called hello. Driver should
//call hello from fand g.
// Jacob Stewart, CIT-245-Z01, 10/19/2021

int main() {
	helloF();
	helloG();

	system("pause");
	return 1;
}