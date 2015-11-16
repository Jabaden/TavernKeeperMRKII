#include "GameplayManager.h"

GameplayManager::GameplayManager(){
	this->isPouring = false;
	this->isPouring = false;
	this->pourClock = new sf::Clock();

	this->shakerIngredients = new sVec();
	this->shakerAmount = new iVec();

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


//Looks at both the tool and the ingredient and sees if they are compatable
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

//starts a round of adding ingredients to the jigger
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
		if (ingredient->getSprite()->getRotation() < 200 && ingredient->getSprite()->getRotation() > 50){
			
		}
		else{
			ingredient->getSprite()->rotate(-.04);
			pourClock->restart();
		}
		
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

//Ends the current pouring session
void GameplayManager::endPouringGame(ToolSelector* ts, DrinkSelector* ds){


	this->togglePouring();

	this->addIngredient(ts, ds);

	ds->getDVector()->at(ds->getPosition())->recall();
	ts->getTVector()->at(ts->getPosition())->recall();
	ts->getTVector()->at(ts->getPosition())->resetCompletion();

	
}
//adds the name aka ingredient to the shaker (the currently mixed drink)
//and also adds to the interal counter that sees how much each drink has been added
//this internal counter is in the Drink Selector class (dont ask why)
void GameplayManager::addIngredient(ToolSelector* ts, DrinkSelector* ds){
	Tool* someTool = ts->getTVector()->at(ts->getPosition());
	Drink* someDrink = ds->getDVector()->at(ds->getPosition());

	this->shakerIngredients->push_back(someDrink->getName());

	if (someDrink->getName() == "Whiskey"){
		ds->setWhiskeyAmount(ds->getWhiskeyAmount() + someTool->getCompletion());
	}
	else if (someDrink->getName() == "Ale"){
		ds->setAleAmount(ds->getAleAmount() + someTool->getCompletion());
	}
	else if (someDrink->getName() == "Wine"){
		ds->setWineAmount(ds->getWhiskeyAmount() + someTool->getCompletion());
	}
	else if (someDrink->getName() == "Firewater"){
		ds->setFirewaterAmount(ds->getFirewaterAmount() + someTool->getCompletion());
	}
	else if (someDrink->getName() == "Garnish"){
		ds->setGarnishAmount(ds->getGarnishAmount() + someTool->getCompletion());
	}

	this->shakerAmount->push_back(someTool->getCompletion());
}

void GameplayManager::emptyShaker(){
	this->shakerAmount->clear();
}

void GameplayManager::checkIfRightDrink(DrinkDeck* dDeck, string aDrink){
	int cavPosition = 0;
	std::vector<DrinkCard*>* orderDeck = dDeck->getOrderQueue();
	std::vector<bool>* cav = orderDeck->at(0)->getCAV();
	DrinkCard* orderCard = dDeck->getOrderQueue()->at(0);
	cout << "order card is ";
	orderCard->printCard();


	string cardName = orderCard->getName();
	string cardType = orderCard->getType();
	string cardFlavorZero = orderCard->getFlavorArrayZero();
	string cardFlavorOne = orderCard->getFlavorArrayOne();

	string drinkName = "";
	string drinkType = "";
	string drinkFlavorZero = "";
	string drinkFlavorOne = "";

	bool wantsFlavor = false;
	bool wantsName = false;
	bool wantsType = false;

	if (aDrink == "Fireball"){
		drinkName = "Fireball";
		drinkType = "Mixed";
		drinkFlavorZero = "Spicy";
		drinkFlavorOne = "Strong";

	}
	else if (aDrink == "FOW"){
		drinkName = "FOW";
		drinkType = "Mixed";
		drinkFlavorZero = "Strong";
		drinkFlavorOne = "Sweet";
	}
	else if (aDrink == "Wine"){
		drinkName = "Wine";
		drinkType = "Boozey";
		drinkFlavorZero = "Smooth";
		drinkFlavorOne = "Sweet";
	}
	else if (aDrink == "Ale"){
		drinkName = "Ale";
		drinkType = "Mixed";
		drinkFlavorZero = "Smooth";
		drinkFlavorOne = "Smooth";
	}
	else if (aDrink == "Whiskey"){
		drinkName = "Whiskey";
		drinkType = "Mixed";
		drinkFlavorZero = "Strong";
		drinkFlavorOne = "Sweet";
	}
	else{
		drinkName = "errorName";
		drinkType = "errorType";
		drinkFlavorZero = "flavorError";
		drinkFlavorOne = "flavorError";
	}

	for (auto iter = cav->begin(); iter != cav->end(); iter++){
		bool tempBool = (*iter);
		cout << "tempbool is " << tempBool << endl;
		if (tempBool){
			if (cavPosition == 0){
				wantsName = true;
			}
			else if (cavPosition == 1){
				wantsType = true;
			}
			else{
				wantsFlavor = true;
			}
		}
		cavPosition++;
		
	}

	if (wantsName){
		if (drinkName == cardName){
			cout << "It worked boys! (name)" << endl;
		}
		else{
			cout << "It didnt work boys! (name)" << endl;
		}
	}
	else if (wantsType){
		if (drinkType == cardType){
			cout << "its Worked boys (type)" << endl;
		}
		else{
			cout << "it didnt work (type)" << endl;
		}
	}
	else if (wantsFlavor){
		if (drinkFlavorZero == cardFlavorZero || drinkFlavorZero == cardFlavorOne || drinkFlavorOne == cardFlavorZero || drinkFlavorOne == cardFlavorOne){
			cout << "its worked boys (flavor)" << endl;
		}
		else{
			cout << "its over bosy (flavor)" << endl;
		}
	}
	dDeck->getOrderCardQueue()->erase(dDeck->getOrderCardQueue()->begin());
	dDeck->decrementNOO();
}

string GameplayManager::ascertainDrink(DrinkSelector* ds){
	vector<string>* fireRecipe = ds->getFireballRecipe();
	string returnDrink = "";
	if (this->isFireball(ds)){
		returnDrink = "Fireball";
		ds->resetDrinkAmounts();
		return returnDrink;
	}
	if (this->isFow(ds)){
		returnDrink = "FOW";
		ds->resetDrinkAmounts();
		return returnDrink;
	}
	else{
		returnDrink = "Error";
		ds->resetDrinkAmounts();
		return returnDrink;
	}
	//if (this->shakerIngredients)

	//string fuckYou = "stop";
	//return fuckYou;
}

bool GameplayManager::isFireball(DrinkSelector* ds){
	if (ds->getFirewaterAmount() == 100 && ds->getWhiskeyAmount() == 200 && ds->getAleAmount() == 100){
		if (ds->getGarnishAmount() == 0 && ds->getWineAmount() == 0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool GameplayManager::isFow(DrinkSelector* ds){
	if (ds->getWineAmount() == 200 && ds->getAleAmount() == 200){
		if (ds->getGarnishAmount() == 0 && ds->getWhiskeyAmount()){
			return true;
		}
		else{ return false; }
	}
	else{ return false; }
}

