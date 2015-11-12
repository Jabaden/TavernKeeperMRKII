#include <SFML/Graphics.hpp>
#include "Drink.h"
#include <vector>
using namespace std;
class DrinkSelector{
private:
	typedef vector<Drink*> dVec;
	dVec* drinkVector;
	int position;
public:
	DrinkSelector();
	void render(sf::RenderWindow* wnd);
	void incrementDrink();
	void decrementDrink();
	void raiseDrink();
	void lowerDrink();
	void choose();

	dVec* getDVector();

	int getPosition();
};