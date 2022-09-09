#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
//Part 1
//Create an int i with a value of 7. Create a pointer to integer pi.Point your pointer pi to your int variable i.Print
//out your pointer, the address of your pointerand a dereference of your pointer.
//Create a pointer to your integer pointer ppi.Point it to your pointer to int pi.Print out ppi, the address of ppi, a
//dereference to ppiand a double dereference to ppi.
//Part 2
//Understanding deep vs.shallow copy is essential for a programmer.You will get into severe problems trying to
//code if you do not understand it.
//The essence of the problem is that 2 objects, which should have independent memory storage, accidently wind
//up sharing memory.
//I want you to wrap a character array(and array with 'a', 'b', 'c', 'd', 'e' is strictly speaking not a string since it does
//    not end in '\0') with a class (this is just a class that contains an array) and then properly(in Deep) and improperly
//    (in Shallow) assign memory.
//    Make a class WrapArrayDeep that has a private pointer to char.Your default constructor should allocate an
//    array of size 5. You should have a copy constructor that does a deep copy. (allocates a new array)
// Jacob Stewart, CIT-245-Z01, 10/12/2021

class WrapArrayDeep {
private:
    char* pch;
public:
    WrapArrayDeep() {
        pch = new char[5];
        *pch = 97;
        *(pch + 1) = 98;
        *(pch + 2) = 99;
        *(pch + 3) = 100;
        *(pch + 4) = 101;
    }
    WrapArrayDeep(const WrapArrayDeep& wad) {
        pch = new char[5];
        for (int i = 0; i < 5; i++) {
            pch[i] = wad.pch[i];
        }
    }
    void display() {
        for (int i = 0; i < 5; i++) {
            cout << pch[i] << " ";
        }
        cout << endl;
    }
    void change() {
        for (int i = 0; i < 5; i++) {
            pch[i] += 5;
        }
    }
    ~WrapArrayDeep() {
        delete[] pch;
        cout << "DEEP ARRAY DESTROYED\n";
    }
};
class WrapArrayShallow {
private:
    char* pch;
public:
    WrapArrayShallow() {
        pch = new char[5];
        pch[0] = 'v';
        pch[1] = 'w';
        pch[2] = 'x';
        pch[3] = 'y';
        pch[4] = 'z';
    }
    WrapArrayShallow(const WrapArrayShallow& was) {
        pch = was.pch;
    }
    void display() {
        for (int i = 0; i < 5; i++) {
            cout << *(pch + i) << " ";
        }
        cout << endl;
    }

    void change() {
        for (int i = 0; i < 5; i++) {
            *(pch + i) += 5;
        }
    }
    // Causes crash
    /*~WrapArrayShallow() {
            delete[] pch;
            cout << "SHALLOW ARRAY DESTROYED\n";
    }*/
};
int main() {
	//**************PART 1*********************
	int i = 7;
	int* pi, ** ppi;
	pi = &i;
	cout << "Adress of i = " << &i << "\npi = " << pi << "\nAddress of pi = " 
		<< &pi << "\nDereference of pi = " << *pi << endl;
	ppi = &pi;
	cout << "\nppi = " << ppi << "\nAddress of ppi = " << &ppi 
		<< "\nDereference of ppi = " << *ppi 
		<< "\nDouble dereference of ppi = " << **ppi << endl;
	//**************PART 1*********************
	//**************PART 2*********************
    WrapArrayDeep wad1;
    WrapArrayShallow was1;
    cout << "\nWrapper class for dynamic array of 5 characters\nWrapArrayDeep 1\n";
    
    wad1.display();
    WrapArrayDeep wad2 = wad1;
    cout << "WrapArrayDeep 2\n";
    wad2.display();
    wad2.change();
    cout << "\nWrapArrayDeep 1 after change\n";
    wad1.display();
    cout << "WrapArrayDeep 2 after change\n";
    wad2.display();

    cout << "\nWrapArrayShallow 1\n";
    was1.display();
    WrapArrayShallow was2 = was1;
    cout << "WrapArrayShallow 2\n";
    was2.display();
    was2.change();
    cout << "\nWrapArrayShallow 1 after change\n";
    was1.display();
    cout << "WrapArrayShallow 2 after change\n";
    was2.display();
	//**************PART 2*********************
	system("pause");
	return 1;
}
