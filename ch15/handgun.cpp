#include <string>
#include <cstdlib>
#include <iostream>
#include "handgun.h"
using std::string;
using std::cout;

namespace StewartGuns {
    HandGun::HandGun() : Gun(), grip("manufacturer's"), sight("manufacturer's sight"), laser(false) {}
    HandGun::HandGun(const string& theManu, const string& theCali, const string& theGrip, const string& theSight, const bool& theLaser) : Gun(theManu, theCali), grip(theGrip), sight(theSight), laser(theLaser) {}
    string HandGun::getGrip() const { return grip; }
    string HandGun::getSight() const { return sight; }
    bool HandGun::getLaser() const { return laser; }
    void HandGun::setGrip(const string& newGrip) { grip = newGrip; }
    void HandGun::setSight(const string& newSight) { sight = newSight; }
    void HandGun::setLaser(const bool& newLaser) { laser = newLaser; }
    void HandGun::print() const {
        cout << "\nError: printCheck function called for an \n"
            << "undifferentiated handgun. Aborting the program.\n";
        exit(1);
    }
}