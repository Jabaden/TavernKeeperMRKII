#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class Drink{
private:
	sf::Sprite* drinkSprite;
	sf::Texture* drinkTexture;
	string name;
	string type;
	string flavor;
	int xPosition;
	int yPosition;
	int baseYPosition;
	int baseXPosition;
	bool currentlyPouring;
public:
	Drink(int xPos, int yPos, string name);
	void render(sf::RenderWindow* wnd);
	sf::Sprite* getSprite();
	int getXPos();
	int getYpos();
	int getBaseXPos();
	int getBaseYPos();
	void setXPos(int x);
	void setYPos(int y);
	void recall();
	string getName();
	bool isCurrentlyPouring();
	void setCurrentlyPouringTrue();
	void setCurrentlyPouringFalse();
};