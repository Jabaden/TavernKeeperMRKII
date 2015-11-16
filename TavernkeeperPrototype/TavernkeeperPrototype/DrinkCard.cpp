#include "DrinkCard.h"

DrinkCard::DrinkCard(string aName, string aType, string flavor[]){
	this->name = aName;
	this->type = aType;
	this->chosenAttributeVector = new DrinkCard::bVector();
	this->chosenAttributeVector->push_back(false);
	this->chosenAttributeVector->push_back(false);
	this->chosenAttributeVector->push_back(false);
	for (int i = 0; i < 2; i++){
		flavorArray[i] = flavor[i];
		//std::cout << flavorArray[i];
	}
	//TODO NEW VECTOR AND INSERT DEFAULT BOOLEAN VALUES
}

void DrinkCard::drinkCardTest(){
	//std::cout << "HELLO THIS IS MICHELLE" << std::endl;
}

void DrinkCard::printCard(){
	cout << "Name: " << this->name << ". Type: " << this->type << ". Flavors: " << this->flavorArray[0] << ", " << this->flavorArray[1] << endl;
	//cout << "inside printCard()" << endl;
}

void DrinkCard::pickRandomAttribute(){
	int random = rand() % 3;
	cout << to_string(random) << endl;
	this->chooseAttribute(random);
	this->printCAV();

	//TODO
}

void DrinkCard::chooseAttribute(int attribute){
	switch (attribute){
	case(0) :
		this->chosenAttributeVector->at(0) = true;
		this->chosenAttributeVector->at(1) = false;
		this->chosenAttributeVector->at(2) = false;
		break;
	case(1) :
		this->chosenAttributeVector->at(0) = false;
		this->chosenAttributeVector->at(1) = true;
		this->chosenAttributeVector->at(2) = false;
		break;
	case(2) :
		this->chosenAttributeVector->at(0) = false;
		this->chosenAttributeVector->at(1) = false;
		this->chosenAttributeVector->at(2) = true;
		break;
	}
}

//TODO this will print to console and display what the order is!
void DrinkCard::orderUp(){

}

void DrinkCard::printCAV(){
	for (auto iter = this->chosenAttributeVector->begin(); iter != this->chosenAttributeVector->end(); iter++){
		if ((*iter)){
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}
}
//figures out what the customer is asking for based on the boolean values in the attributeVector
string DrinkCard::describeOrder(){
	string myOrder = "";
	int i = 0;
	for (auto iter = this->chosenAttributeVector->begin(); iter != this->chosenAttributeVector->end(); iter++){
		if ((*iter) && i == 0){
			cout << "Get me a " << this->name << "!" << endl;
			myOrder = "Get me a " + this->name + "!";
			return myOrder;
		}
		else if ((*iter) && i == 1){
			cout << "Get me a " << this->type << " Drink!" << endl;
			myOrder = "Get me a " + this->type + " Drink!";
			return myOrder;
		}
		else if ((*iter) && i == 2){
			if (this->flavorArray[0] == this->flavorArray[1]){
				cout << "Get me a " << this->flavorArray[0] << " drink!" << endl;
				myOrder = "Get me a " + this->flavorArray[0] + " drink!";
			}
			else{
				cout << "Get me a " << this->flavorArray[0] << " or a " << this->flavorArray[1] << " drink!" << endl;
				myOrder = "Get me a " + this->flavorArray[0] + " or a " + this->flavorArray[1] + " drink!"; 
			}
			return myOrder;
		}
		i++;
	}
}

DrinkCard::bVector* DrinkCard::getCAV(){
	return this->chosenAttributeVector;
}

string DrinkCard::getFlavorArrayZero(){
	return this->flavorArray[0];
}

string DrinkCard::getFlavorArrayOne(){
	return this->flavorArray[1];
}

string DrinkCard::getType(){
	return this->type;
}

string DrinkCard::getName(){
	return this->name;
}
