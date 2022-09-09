#include <string>
#include <cstdlib>
#include <iostream>
#include "revolver.h"
using std::string;
using std::cout;
using std::endl;

namespace StewartGuns {
	Revolver::Revolver() : HandGun(), singleAction(true), numberOfRounds(0) {}
	Revolver::Revolver(const string& theManu, const string& theCali,
		const string& theGrip, const string& theSight,
		const bool& theLaser, const bool& isSingleAction, const int& theNumberOfRounds)
		: HandGun(theManu, theCali, theGrip, theSight, theLaser), singleAction(isSingleAction), numberOfRounds(theNumberOfRounds) {}
	bool Revolver::getSingleAction() const { return singleAction; }
	int Revolver::getNumberOfRounds() const { return numberOfRounds; }
	void Revolver::setSingleAction(const bool& newSingleAction) { singleAction = newSingleAction; }
	void Revolver::setNumberOfRounds(const int& newNumberOfRounds) { numberOfRounds = newNumberOfRounds; }
	void Revolver::print() const {
		cout << "Revolver: " << getManu() << ", "
			<< getCali() << ", " << getNumberOfRounds() << " shot, ";
		if (getSingleAction()) cout << "single action, ";
		else cout << "double action, ";
		cout << getGrip() << " grips, ";
		if (getLaser()) cout << "laser, ";
		else cout << "no laser, ";
		cout << getSight() << endl;
	}
}