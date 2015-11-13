#include "GameplayManager.h"

GameplayManager::GameplayManager(){
	this->isPouring = false;
	this->isPouring = false;

	this->pourClock = new sf::Clock();
}

void GameplayManager::togglePouring(){
	if (this->isPouring){
		this->isPouring = false;
	}
	else{
		this->isPouring = true;
	}
}

void GameplayManager::togglePeeling(){
	if (this->isPeeling){
		this->isPeeling = false;
	}
	else{
		this->isPeeling = true;
	}
}
//check if any boolean values are true. If so, start the minigame. 
void GameplayManager::gameCheck(ToolSelector* ts, DrinkSelector* ds){

	if (this->isPouring){
		this->pouringGame(ts, ds);
	}
}

bool GameplayManager::getPeeling(){
	return this->isPeeling;
}

bool GameplayManager::getPouring(){
	return this->isPouring;
}

void GameplayManager::compareHands(ToolSelector* ts, DrinkSelector* ds, GameplayManager* manager){
	//bigg jig, little jig, spoon, peeler, knife
	//Ale, Firewater, whiskey, Wine, Garnish

	Drink* ingredient = ds->getDVector()->at(ds->getPosition());
	Tool* tool = ts->getTVector()->at(ts->getPosition());

	string ingredientName = ingredient->getName();
	string toolName = tool->getName();

	if (toolName == "Big Jigger" || toolName == "Little Jigger"){
		if (ingredientName != "Garnish"){
			manager->togglePouring();
			cout << "The getPouring is";
			cout << manager->getPouring() << endl;
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

void GameplayManager::pouringGame(ToolSelector* ts, DrinkSelector* ds){
	Drink* ingredient = ds->getDVector()->at(ds->getPosition());
	Tool* tool = ts->getTVector()->at(ts->getPosition());

	//cout << "am I pouring? " << ingredient->isCurrentlyPouring() << endl;

	//cout << "the rotation is " << ingredient->getSprite()->getRotation() << endl;

	//if (ingredient->getSprite()->getRotation() > 0){
		//ingredient->getSprite()->setRotation(0);
	//}
	if (ingredient->isCurrentlyPouring() == false && (ingredient->getSprite()->getRotation() != 0) && pourClock->getElapsedTime().asSeconds() > .10){
		ingredient->getSprite()->rotate(.04);
		//pourClock->restart();
		if (ingredient->getSprite()->getRotation() > 0 && ingredient->getSprite()->getRotation() < 10){
			ingredient->getSprite()->setRotation(0);
		}
	}
	else if (ingredient->isCurrentlyPouring()){
		ingredient->getSprite()->rotate(-.04);
		pourClock->restart();
	}
		if (ingredient->getSprite()->getRotation() < 215 && ingredient->getSprite()->getRotation() > 50){
			//cout << "im pouring a ton of shit!" << endl;
			tool->incrementCompletion(3);
		}
		else if (ingredient->getSprite()->getRotation() < 235 && ingredient->getSprite()->getRotation() > 50){
			//cout << "im pouring some shit!" << endl;
			tool->incrementCompletion(2);
		}
		else if (ingredient->getSprite()->getRotation() < 260 && ingredient->getSprite()->getRotation() > 50){
			//cout << "im not pouring much shit..." << endl;
			tool->incrementCompletion(1);
		}
		
	
	
}