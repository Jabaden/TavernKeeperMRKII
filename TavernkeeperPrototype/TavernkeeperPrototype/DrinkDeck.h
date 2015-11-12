#include <SFML/Graphics.hpp>
#include <vector>
#include "DrinkCard.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>

using namespace std;
class DrinkDeck{
private:
	typedef std::vector<DrinkCard*> dVec;
	dVec* deckOfDrinks;
public:
	DrinkDeck();
	dVec* getDeck();
	DrinkCard* drawCard();
	void shuffleDeck();
	void printDeck();
};