#include <SFML/Graphics.hpp>
#include <vector>
#include "DrinkCard.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <algorithm>

using namespace std;
class DrinkDeck{
private:
	int numberOfOrders;
	typedef std::vector<DrinkCard*> dVec;
	typedef std::vector<Order*> oVec;
	dVec* deckOfDrinks;
	dVec* orderQueue;
	oVec* orderCardQueue;

public:
	DrinkDeck();
	dVec* getDeck();
	dVec* getOrderQueue();
	oVec* getOrderCardQueue();
	DrinkCard* drawCard();
	void shuffleDeck();
	void printDeck();
	void renderOrders(sf::RenderWindow* wnd);
	void printOrderQueue();
	void decrementNOO();
};