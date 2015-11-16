#include "DrinkDeck.h"
DrinkDeck::DrinkDeck(){
	numberOfOrders = 0;

	deckOfDrinks = new dVec();
	orderQueue = new dVec();
	orderCardQueue = new oVec();

	ifstream file("DeckOfDrinks.txt");
	string currentLine = "";
	string remainder = "";
	string dName = "";
	string dType = "";
	string dFlavorArray[2];
	string dFlavorOne = "";
	string dFlavorTwo = "";

	int stringStart = 0;
	int stringEnd = 0;

	//Reading from a file to fill a drink deck
	if (file.is_open()){
		while (getline(file, currentLine)){
			string linetype = currentLine.substr(0, 1);
			if (linetype == "#"){
				cout << "# found, line skipped" << endl;
				continue;
			}

			//cout << currentLine << endl;
			stringStart = currentLine.find_first_of("&");
			//" \t" is whitespace
			stringEnd = currentLine.find_first_of(" \t", stringStart + 1);
			//cout << "start is at " << to_string(stringStart) << " and finishes at " << to_string(stringEnd) << endl;
			remainder = currentLine.substr(stringStart + 1, stringEnd - 1);
			//cout << "another test " << currentLine.substr(0, 2) << remainder << "ahhh" << endl;
			//cout << "remainder is " << remainder << endl;
			dName = remainder;
			stringStart = stringEnd + 1;
			remainder = currentLine.substr(stringStart);
			stringEnd = remainder.find_first_of(" \t");
			stringStart = 1;

			currentLine = remainder;
			remainder = remainder.substr(stringStart, stringEnd - 1);
			stringStart = stringEnd;
			dType = remainder;
			remainder = currentLine.substr(stringStart + 2); //gets rid of &
			//cout << "the type is " << dType << endl;

			currentLine = remainder;
			stringEnd = remainder.find_first_of(" \t");
			remainder = remainder.substr(0, stringEnd);

			dFlavorOne = remainder;
			remainder = currentLine;
			stringStart = stringEnd;
			remainder = remainder.substr(stringStart + 1);
			//cout << "remainder is " << remainder << " no tricks!" << endl;
			dFlavorTwo = remainder;

			dFlavorArray[0] = dFlavorOne;
			dFlavorArray[1] = dFlavorTwo;

			DrinkCard* tempCard = new DrinkCard(dName, dType, dFlavorArray);
			deckOfDrinks->push_back(tempCard);
			//cout << "Your drink is called " << dName << ". it is a " << dType << " drink. It is " << dFlavorOne << " and " << dFlavorTwo << endl;
			//cout << to_string(deckOfDrinks->size()) << endl;
		}
		file.close();
	}
}

DrinkDeck::dVec* DrinkDeck::getDeck(){
	return this->deckOfDrinks;
}

DrinkDeck::dVec* DrinkDeck::getOrderQueue(){
	return this->orderQueue;
}

DrinkCard* DrinkDeck::drawCard(){
	//this->shuffleDeck();
	this->numberOfOrders++;

	Order* newOrder = new Order(numberOfOrders);

	string tempOrder = "";
	DrinkCard* card = deckOfDrinks->back();
	card->pickRandomAttribute();
	//cout << " Inside draw card" << endl;
	card->printCard();

	//displays the order popup
	newOrder->createCard(card->describeOrder());
	//cout << "describeOrder" << card->describeOrder() << endl;
	orderCardQueue->push_back(newOrder);

	//adds this to the order queue
	this->orderQueue->push_back(card);

	//takes it out of the drink deck
	//THIS IS A TEST, PLEASE CHECK HERE---------------------------------------------------------------------------------
	this->shuffleDeck();
	//deckOfDrinks->pop_back();
	return card;
}

void DrinkDeck::shuffleDeck(){
	random_shuffle(this->deckOfDrinks->begin(), this->deckOfDrinks->end());
}

void DrinkDeck::printDeck(){
	for (auto iter = this->deckOfDrinks->begin(); iter != this->deckOfDrinks->end(); iter++){
		(*iter)->printCard();
	}
}

void DrinkDeck::renderOrders(sf::RenderWindow* wnd){
	for (auto iter = this->orderCardQueue->begin(); iter != this->orderCardQueue->end(); iter++){
		(*iter)->render(wnd);
	}
}

void DrinkDeck::printOrderQueue(){
	for (auto iter = this->orderQueue->begin(); iter != this->orderQueue->end(); iter++){
		(*iter)->printCard();
	}
}

DrinkDeck::oVec* DrinkDeck::getOrderCardQueue(){
	return this->orderCardQueue;
}

void DrinkDeck::decrementNOO(){
	this->numberOfOrders--;
}