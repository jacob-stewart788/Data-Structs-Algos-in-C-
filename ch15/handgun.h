#ifndef HANDGUN_H
#define HANDGUN_H
#include <string>
#include "gun.h"
using std::string;

namespace StewartGuns {
    class HandGun : public Gun {
    public:
        HandGun();
        HandGun(const string& theManu, const string& theCali,
            const string& theGrip, const string& theSight, const bool& theLaser);
        string getGrip() const;
        string getSight() const;
        bool getLaser() const;
        void setGrip(const string& newGrip);
        void setSight(const string& newSight);
        void setLaser(const bool& newLaser);
        void print() const override;
    private:
        string grip;
        string sight;
        bool laser;
    };
}
#endif