#ifndef REVOLVER_H
#define REVOLVER_H
#include <string>
#include "handgun.h"
using std::string;

namespace StewartGuns {
    class Revolver : public HandGun {
    public:
        Revolver();
        Revolver(const string& theManu, const string& theCali,
            const string& theGrip, const string& theSight, const bool& theLaser, const bool& isSingleAction, const int& theNumberOfRounds);
        bool getSingleAction() const;
        int getNumberOfRounds() const;
        void setSingleAction(const bool& newSingleAction);
        void setNumberOfRounds(const int& newNumberOfRounds);
        void print() const override;
    private:
        bool singleAction;
        int numberOfRounds;
    };

}
#endif