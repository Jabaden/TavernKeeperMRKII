#include "Tool.h"

Tool::Tool(int xPos, int yPos, string aName){
	toolSprite = new sf::Sprite();
	toolTexture = new sf::Texture();
	toolTexture->loadFromFile("corgi.png");
	toolSprite->setTexture(*(toolTexture));
	toolSprite->setPosition(xPos, yPos);
	toolSprite->setScale(.20f, .20f);

	xPosition = xPos;
	yPosition = yPos;

	baseXPosition = xPosition;
	baseYPosition = yPosition;
	this->name = aName;

}

void Tool::render(sf::RenderWindow* wnd){
	wnd->draw(*(this->toolSprite));
}

sf::Sprite* Tool::getSprite(){
	return this->toolSprite;
}

void Tool::setXPos(int x){
	this->xPosition = x;
	this->getSprite()->setPosition(xPosition, yPosition);
}

void Tool::setYPos(int y){
	this->yPosition = y;
	this->getSprite()->setPosition(xPosition, yPosition);
}

int Tool::getXPos(){
	return this->xPosition;
}

int Tool::getYpos(){
	return this->yPosition;
}

int Tool::getBaseXPos(){
	return this->baseXPosition;
}

int Tool::getBaseYPos(){
	return this->baseYPosition;
}

void Tool::recall(){
	this->setXPos(this->baseXPosition);
	this->setYPos(this->baseYPosition);
}

string Tool::getName(){
	return this->name;
}