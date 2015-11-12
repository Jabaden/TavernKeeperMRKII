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

DrinkSelector::dVec* DrinkSelector::getDVector(){
	return this->drinkVector;
}

int DrinkSelector::getPosition(){
	return this->position;
}




