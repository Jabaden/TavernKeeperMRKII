#include "Drink.h"
#include <iostream>
Drink::Drink(int xPos, int yPos, string aName){
	//std::cout << "test";
	drinkSprite = new sf::Sprite();
	drinkTexture = new sf::Texture();
	drinkTexture->loadFromFile("ScaryFace-2.png");
	drinkSprite->setTexture(*(drinkTexture));
	drinkSprite->setPosition(xPos, yPos);
	drinkSprite->setScale(.5f, .5f);

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
}

string Drink::getName(){
	return this->name;
}