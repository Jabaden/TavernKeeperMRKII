#include "SFML\Graphics.hpp"
#include "DrinkSelector.h"
#include "ToolSelector.h"
#include "DrinkDeck.h"
class GameplayManager{
private: 
	bool isPouring;
	bool isPeeling;
	sf::Clock* pourClock;
	typedef vector<string> sVec;
	typedef vector<int> iVec;
	sVec* shakerIngredients;
	iVec* shakerAmount;
public:
	GameplayManager();
	void togglePouring();
	void togglePeeling();
	void gameCheck(ToolSelector* ts, DrinkSelector* ds);
	void compareHands(ToolSelector* ts, DrinkSelector* ds, GameplayManager* manager);
	void checkIfRightDrink(DrinkDeck* dDeck, string aDrink);

	bool getPouring();
	bool getPeeling();
	bool isFireball(DrinkSelector* ds);
	bool isFow(DrinkSelector* ds);

	void pouringGame(ToolSelector* ts, DrinkSelector* ds);
	void endPouringGame(ToolSelector* ts, DrinkSelector* ds);
	void addIngredient(ToolSelector* ts, DrinkSelector* ds);

	void emptyShaker();

	string ascertainDrink(DrinkSelector* ds);


	
};