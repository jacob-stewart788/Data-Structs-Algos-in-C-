#include <string>
#include <cstdlib>
#include <iostream>
#include "pistol.h"
using std::string;
using std::cout;
using std::endl;

namespace StewartGuns {
	Pistol::Pistol() : HandGun(), semiAuto(true) {}
	Pistol::Pistol(const string& theManu, const string& theCali,
		const string& theGrip, const string& theSight, const bool& theLaser, const bool& isSemiAuto)
		: HandGun(theManu, theCali, theGrip, theSight, theLaser), semiAuto(isSemiAuto) {}
	bool Pistol::getSemiAuto() const { return semiAuto; }
	void Pistol::setSemiAuto(const bool& newSemiAuto) { semiAuto = newSemiAuto; }
	void Pistol::print() const {
		cout << "Pistol: " << getManu() << ", " << getCali() << ", ";
		if (getSemiAuto()) cout << "semi-auto, ";
		else cout << "auto, ";
		cout << getGrip() << " grips, ";
		if (getLaser()) cout << "laser, ";
		else cout << "no laser, ";
		cout << getSight() << endl;
	}
}