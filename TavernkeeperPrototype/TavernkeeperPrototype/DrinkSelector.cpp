#include "DrinkSelector.h"
//#include "GameVariables.h"

//Ale, Firewater, whiskey, Wine, Garnish

DrinkSelector::DrinkSelector(){
	position = 0;

	Drink* testDrink = new Drink(1920 - 600, 1080 - 200, "Ale");
	Drink* testDrink2 = new Drink(1920 - 500, 1080 - 200, "Firewater");
	Drink* testDrink3 = new Drink(1920 - 400, 1080 - 200, "Whiskey");
	Drink* testDrink4 = new Drink(1920 - 300, 1080 - 200, "Wine");
	Drink* testDrink5 = new Drink(1920 - 200, 1080 - 200, "Garnish");

	drinkVector = new dVec();
	drinkVector->push_back(testDrink);
	drinkVector->push_back(testDrink2);
	drinkVector->push_back(testDrink3);
	drinkVector->push_back(testDrink4);
	drinkVector->push_back(testDrink5);

	fireballRecipe = new sVec();
	fireballRecipe->push_back("Whiskey");
	fireballRecipe->push_back("Ale");
	fireballRecipe->push_back("Firewater");

	fowRecipe = new sVec();
	fowRecipe->push_back("Wine");
	fowRecipe->push_back("Ale");

	aleRecipe = new sVec();
	aleRecipe->push_back("Ale");
	aleRecipe->push_back("Garnish");

	wineRecipe = new sVec();
	wineRecipe->push_back("Wine");

	whiskeyRecipe = new sVec();
	whiskeyRecipe->push_back("Whiskey");



}

void DrinkSelector::render(sf::RenderWindow* wnd){
	for (auto iter = this->drinkVector->begin(); iter != this->drinkVector->end(); iter++){
		(*iter)->render(wnd);
	}
}

void DrinkSelector::incrementDrink(){
	this->position++;
	if (this->position > 4){
		this->position = 0;
	}
}

void DrinkSelector::decrementDrink(){
	this->position--;
	if (this->position < 0){
		this->position = 4;
	}
	cout << to_string(this->position) << " fuck this" << endl;
}

void DrinkSelector::raiseDrink(){
	cout << "this is a test" << endl;
	Drink* tempDrink = (this->drinkVector->at(this->position)); 
	Drink* tempDrinkLeft;
	Drink* tempDrinkRight;
	if (this->position == 0){
		tempDrinkLeft = (this->drinkVector->at(4));
	}
	else{
		tempDrinkLeft = this->drinkVector->at((this->position) - 1);
	}

	if (this->position == 4){
		tempDrinkRight = this->drinkVector->at(0);
	}
	else{
		tempDrinkRight = this->drinkVector->at((this->position) + 1);
	}

	tempDrink->setYPos(tempDrink->getYpos() - 100);
	//tempDrinkLeft->setYPos(tempDrinkLeft->getBaseYPos());
	//tempDrinkRight->setYPos(tempDrinkRight->getBaseYPos());
	tempDrinkLeft->recall();
	tempDrinkRight->recall();

}

void DrinkSelector::choose(){
	Drink* chosenDrink = (this->drinkVector->at(this->position));
	chosenDrink->setXPos(1050);
	chosenDrink->setYPos(500);
}

void DrinkSelector::setAleAmount(int amount){
	this->aleAmount = amount;
}

void DrinkSelector::setFirewaterAmount(int amount){
	this->firewaterAmount = amount;
}

void DrinkSelector::setGarnishAmount(int amount){
	this->garnishAmount = amount;
}

void DrinkSelector::setWhiskeyAmount(int amount){
	this->whiskeyAmount = amount;
}

void DrinkSelector::setWineAmount(int amount){
	this->wineAmount = amount;
}


DrinkSelector::dVec* DrinkSelector::getDVector(){
	return this->drinkVector;
}

int DrinkSelector::getPosition(){
	return this->position;
}

int DrinkSelector::getAleAmount(){
	return this->aleAmount;
}

int DrinkSelector::getFirewaterAmount(){
	return this->firewaterAmount;
}

int DrinkSelector::getGarnishAmount(){
	return this->garnishAmount;
}

int DrinkSelector::getWhiskeyAmount(){
	return this->whiskeyAmount;
}

int DrinkSelector::getWineAmount(){
	return this->wineAmount;
}

DrinkSelector::sVec* DrinkSelector::getFireballRecipe(){
	return this->fireballRecipe;
}

void DrinkSelector::resetDrinkAmounts(){
	this->aleAmount = 0;
	this->firewaterAmount = 0;
	this->garnishAmount = 0;
	this->whiskeyAmount = 0;
	this->wineAmount = 0;
}

