#include "SFML\Graphics.hpp"
#include "DrinkSelector.h"
#include "ToolSelector.h"
class GameplayManager{
private: 
	bool isPouring;
	bool isPeeling;
	sf::Clock* pourClock;
public:
	GameplayManager();
	void togglePouring();
	void togglePeeling();
	void gameCheck(ToolSelector* ts, DrinkSelector* ds);
	void compareHands(ToolSelector* ts, DrinkSelector* ds, GameplayManager* manager);

	bool getPouring();
	bool getPeeling();

	void pouringGame(ToolSelector* ts, DrinkSelector* ds);
};