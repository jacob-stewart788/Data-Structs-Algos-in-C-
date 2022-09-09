#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/3/21
//Write a program that computes buoyant force given the radiusand weight of a sphere.Buoyant Force = Volume x Water Weight(62.4
//	lbs / cubic foot).Your program should decide whether a sphere sinks or floats in water.The user inputs the radius of the sphere and the
//	weight.Volume = 4 / 3 pi r ^ 3. Use const double PI = 3.141592; for PI.
//	Your program must prompt for multiple calculations

int main() {
	const double PI = 3.141592;
	double radius, weight, volume, bForce;
	bool calc = true;

	cout << "This program computes Buoyant Force in water given sphere radius."
		<< "\nBased on the weight of the sphere, it determines whether the sphere floats or sinks.\n\n";
		
	while (calc) {
		cout << "Enter the radius of the sphere: ";
		cin >> radius;
		cout << "\nYou entered " << radius
			<< "\n\nEnter the weight of the sphere: ";
		cin >> weight;
		cout << "\nYou entered " << weight;

		volume = (4 / 3.0) * PI * (radius * radius * radius);
		bForce = volume * 62.4;

		cout << "\n\nBouyant Force = " << bForce;
		if (bForce >= weight)
			cout << "\nYeah, it floats!";
		else
			cout << "\nShe's sinking captain!";

		cout << "\nRecalculate? (1 = yes, 0 = exit) : ";
			
		cin >> calc;

		cout << endl;
	}

	system("pause");
	return 0;
}