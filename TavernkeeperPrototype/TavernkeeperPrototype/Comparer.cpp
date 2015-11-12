#include "Comparer.h"
using namespace std;



Comparer::Comparer(){
	return;
}

void Comparer::compareHands(ToolSelector* ts, DrinkSelector* ds, GameplayManager* manager){
	//bigg jig, little jig, spoon, peeler, knife
	//Ale, Firewater, whiskey, Wine, Garnish

	Drink* ingredient = ds->getDVector()->at(ds->getPosition());
	Tool* tool = ts->getTVector()->at(ts->getPosition());

	string ingredientName = ingredient->getName();
	string toolName = tool->getName();

	if (toolName == "Big Jigger" || toolName == "Little Jigger"){
		if (ingredientName != "Garnish"){
			manager->togglePouring();
			return;
		}
	}
	else if (toolName == "Peeler" && ingredientName == "Garnish"){
		manager->togglePeeling();
		return;
	}
	else{
		tool->recall();
		ingredient->recall();
	}

	//get name and then compare, then do stuff. 
}