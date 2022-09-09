#ifndef PISTOL_H
#define PISTOL_H
#include <string>
#include "handgun.h"
using std::string;

namespace StewartGuns {
    class Pistol : public HandGun {
    public:
        Pistol();
        Pistol(const string& theManu, const string& theCali,
            const string& theGrip, const string& theSight, const bool& theLaser, const bool& isSemiAuto);
        bool getSemiAuto() const;
        void setSemiAuto(const bool& newSemiAuto);
        void print() const override;
    private:
        bool semiAuto;
    };

}
#endif
