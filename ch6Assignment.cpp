#pragma warning(disable: 4996)
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
// Jacob Stewart, CIT-245-Z01, 9/25/2021
//Write a class that represents a player in a game.The player should have a name, password,
//experience points, an inventory array of four strings, and a location x, y.Your class should
//have mutator and accessor methods for all variables.For example : setName(), getName().It
//should have a suitable display method.Mutatorsand accessors should be public but all
//variables should be private.To implement get inventory, use string* getInv(); Use the scope
//resolution operator to implement larger methods such as display().Use in class methods for
//shorter methods such as setName(), getName().
class Player {
private:
	string name = "";
	string password = "";
	int exp = 0;
	string inventory[4] = { "", "", "", "" };
	int locationX = 0;
	int locationY = 0;
public:
	void setName(string newName) { name = newName; };
	string getName() { return name; };
	void setPassword(string newPassword) { password = newPassword; };
	string getPassword() { return password; };
	void setExp(int newExp) { exp = newExp; };
	int getExp() { return exp; };
	void setInv(string one, string two, string three, string four);
	string* getInv();
	void setLocation(int newX, int newY) { locationX = newX; locationY = newY; };
	int getLocX() { return locationX; };
	int getLocY() { return locationY; };
	void display();
};
int main() {
	cout << "This program generates three player objects and displays them.\n\n";
	
	Player first, second, third;
	
	first.setName("Nuqlear");
	first.setPassword("alks29834@*#");
	first.setExp(1501);
	first.setInv("Axe", "Helmet", "Shield", "Bread");
	first.setLocation(398, 239);

	second.setName("SLaayYErR928");
	second.setPassword("KSdsifh32");
	second.setExp(13);
	second.setInv("Stick", "Pants", "empty", "empty");
	second.setLocation(5464, 8476);

	third.setName("HARRYPOTTER838");
	third.setPassword("HUFFLEPUFF8383");
	third.setExp(8974565);
	third.setInv("Wand", "Wizard's Robe", "Mana Potion", "Flying Broomstick");
	third.setLocation(878502, 156984);

	first.display();
	second.display();
	third.display();

	system("pause");
	return 1;
}
void Player::setInv(string one, string two, string three, string four){
	inventory[0] = one;
	inventory[1] = two;
	inventory[2] = three;
	inventory[3] = four;
}

string* Player::getInv() { return inventory; }

void Player::display() {

	string* inv = getInv();

	cout << "Player Info - \n"
		<< "Name: " << getName() << endl
		<< "Password: " << getPassword() << endl
		<< "Experience: " << getExp() << endl
		<< "Inventory: \n" << inv[0] << endl << inv[1] 
		<< endl << inv[2] << endl << inv[3] << endl
		<< "Location: " << getLocX() << ", " << getLocY() << "\n\n";
}
