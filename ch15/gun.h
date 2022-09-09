#ifndef GUN_H
#define GUN_H
#include <string>
using std::string;

namespace StewartGuns {
    class Gun {
    public:
        Gun();
        Gun(const string& theManu, const string& theCali);
        string getManu() const;
        string getCali() const;
        void setManu(const string& newManu);
        void setCali(const string& newCali);
        //void printCheck() const;
        virtual void print() const;
    private:
        string manufacturer;
        string caliber;
    };
}
#endif