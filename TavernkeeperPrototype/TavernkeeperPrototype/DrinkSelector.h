#include <SFML/Graphics.hpp>
#include "Drink.h"
#include <vector>
using namespace std;
class DrinkSelector{
private:
	typedef vector<Drink*> dVec;
	typedef vector<string> sVec;
	typedef vector<int> iVec;
	
	//vectors that contain the recipe for each drink
	sVec* fireballRecipe;
	sVec* fowRecipe;
	sVec* aleRecipe;
	sVec* wineRecipe;
	sVec* whiskeyRecipe;
	dVec* drinkVector;

	int position = 0;

	// drink amounts, you compare these to the recipes to see if the correct amount is applied
	int whiskeyAmount = 0;
	int aleAmount = 0;
	int wineAmount = 0;
	int garnishAmount = 0;
	int firewaterAmount = 0;


public:
	DrinkSelector();
	void render(sf::RenderWindow* wnd);
	void incrementDrink();
	void decrementDrink();
	void raiseDrink();
	void lowerDrink();
	void choose();
	void setWhiskeyAmount(int amount);
	void setAleAmount(int amount);
	void setWineAmount(int amount);
	void setGarnishAmount(int amount);
	void setFirewaterAmount(int amount);
	void resetDrinkAmounts();

	dVec* getDVector();

	int getPosition();
	int getWhiskeyAmount();
	int getAleAmount();
	int getWineAmount();
	int getGarnishAmount();
	int getFirewaterAmount();

	sVec* getFireballRecipe();
};