#include "Drink.h"
#include <iostream>
Drink::Drink(int xPos, int yPos, string aName){
	//std::cout << "test";
	drinkSprite = new sf::Sprite();
	drinkTexture = new sf::Texture();
	if (aName == "Whiskey"){
		drinkTexture->loadFromFile("Whiskey.png");
		drinkSprite->setScale(.4f, .4f);
	}
	else if (aName == "Wine"){
		drinkTexture->loadFromFile("Wine.png");
		drinkSprite->setScale(.5f, .5f);
	}
	else if (aName == "Firewater"){
		drinkTexture->loadFromFile("Firewater.png");
		drinkSprite->setScale(.3f, .3f);
	}
	else if (aName == "Ale"){
		drinkTexture->loadFromFile("alebarrel.png");
		drinkSprite->setScale(.7f, .7f);
	}
	else if (aName == "Garnish"){
		drinkTexture->loadFromFile("lemon.png");
		drinkSprite->setScale(.05f, .05f);
	}
	else {
		drinkTexture->loadFromFile("ScaryFace-2.png");
	}
	drinkSprite->setTexture(*(drinkTexture));
	drinkSprite->setPosition(xPos, yPos);


	xPosition = xPos;
	yPosition = yPos;

	baseXPosition = xPosition;
	baseYPosition = yPosition;

	this->name = aName;

}

void Drink::render(sf::RenderWindow* wnd){
	wnd->draw(*(this->drinkSprite));
}

sf::Sprite* Drink::getSprite(){
	return this->drinkSprite;
}

void Drink::setXPos(int x){
	this->xPosition = x;
	this->getSprite()->setPosition(xPosition, yPosition);
}

void Drink::setYPos(int y){
	this->yPosition = y;
	this->getSprite()->setPosition(xPosition, yPosition);
}

int Drink::getXPos(){
	return this->xPosition;
}

int Drink::getYpos(){
	return this->yPosition;
}

int Drink::getBaseXPos(){
	return this->baseXPosition;
}

int Drink::getBaseYPos(){
	return this->baseYPosition;
}

void Drink::recall(){
	this->setXPos(this->baseXPosition);
	this->setYPos(this->baseYPosition);
	this->drinkSprite->setRotation(0);
}

string Drink::getName(){
	return this->name;
}

bool Drink::isCurrentlyPouring(){
	if (this->currentlyPouring){
		return true;
	}
	else{
		return false;
	}
}

void Drink::setCurrentlyPouringFalse(){
	this->currentlyPouring = false;
}

void Drink::setCurrentlyPouringTrue(){
	this->currentlyPouring = true;
}
