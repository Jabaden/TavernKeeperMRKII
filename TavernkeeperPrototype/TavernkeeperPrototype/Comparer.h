#include "DrinkSelector.h"
#include "ToolSelector.h"
#include "GameplayManager.h"

class Comparer{
private:
public:
	Comparer();
	void compareHands(ToolSelector* ts, DrinkSelector* ds, GameplayManager* manager);
};