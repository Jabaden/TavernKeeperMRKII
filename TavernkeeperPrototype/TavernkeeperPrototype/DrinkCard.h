#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class DrinkCard{
private:
	string name;
	string type;
	string flavorArray[2];
	typedef vector<bool> bVector;
	bVector* chosenAttributeVector;
	//0 = name, 1 = type, 2 = flavors. 
	//Used to represent what attribute a patron is calling for
public:
	DrinkCard(string aName, string type, string flavor[2]);
	void printCard();
	void drinkCardTest();
	void pickRandomAttribute();
	void chooseAttribute(int attribute);
	void orderUp();
	string describeOrder();
	void printCAV();

	string getName();
	string getType();
	string getFlavorArrayZero();
	string getFlavorArrayOne();

	bVector* getCAV();
};


