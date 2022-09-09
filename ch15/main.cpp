#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
#include"pistol.h"
#include"revolver.h"
using namespace StewartGuns;
// Jacob Stewart, CIT-245-Z01, 10/19/2021

int main() {

	Revolver rev1("Smith & Wesson", "0.357", "hoague", "Trijicon", true, false, 6);

	Revolver rev2("Colt", ".55", "wood", "night sights", false, true, 8);

	Pistol pistol1("Glock", "9mm", "manufacturer's", "manufacturer's sight", false, false);

	Pistol pistol2("Magnum Research", ".50", "gold", "8x scope", true, true);

	Gun* gunCabinet[4] = { &rev1, &pistol1, &rev2, &pistol2 };

	for (int i = 0; i < 4; i++) {
		gunCabinet[i]->print();
	}

	system("pause");
	return 1;
}