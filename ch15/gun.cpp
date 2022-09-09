#include <string>
#include <cstdlib>
#include <iostream>
#include "gun.h"
using std::string;
using std::cout;

namespace StewartGuns {
    Gun::Gun() : manufacturer("Unknown manufacturer"), caliber("Unknown caliber") {}
    Gun::Gun(const string& theManu, const string& theCali) : manufacturer(theManu), caliber(theCali) {}
    string Gun::getCali() const { return caliber; }
    string Gun::getManu() const { return manufacturer; }
    void Gun::setManu(const string& newManu) { manufacturer = newManu; }
    void Gun::setCali(const string& newCali) { caliber = newCali; }
    void Gun::print() const {
        cout << "\nError: printCheck function called for an \n"
            << "undifferentiated gun. Aborting the program.\n";
        exit(1);
    }
}