#include "Order.h"

Order::Order(int numberOf){
	this->orderBackground = new sf::RectangleShape();
	sf::Vector2f bgSize(350.f, 50.f);
	orderBackground->setSize(bgSize);
	orderBackground->setFillColor(sf::Color::Cyan);
	orderBackground->setPosition(850, -60 + (numberOf * 60));

	this->orderText = new sf::Text();
	this->orderFont = new sf::Font();

	orderFont->loadFromFile("pacText.ttf");

	orderText->setFont(*orderFont);
	orderText->setCharacterSize(30);
	//orderText->setString("Get me a Smooth drink!");
	orderText->setColor(sf::Color::Black);
	orderText->setPosition(orderBackground->getPosition().x, orderBackground->getPosition().y);
}

void Order::render(sf::RenderWindow* wnd){
	wnd->draw(*orderBackground);
	wnd->draw(*orderText);
}

void Order::createCard(string order){
	this->orderText->setString(order);
}

