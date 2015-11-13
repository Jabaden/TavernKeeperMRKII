#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;
class Tool{
private:
	sf::Sprite* toolSprite;
	int xPosition;
	int yPosition;
	int baseXPosition;
	int baseYPosition;
	sf::Texture* toolTexture;
	int completion;
	int completionThreshold;
	int tempCompletion;
	string name;

public:
	Tool(int xPos, int yPos, string name);
	sf::Sprite* getSprite();
	void render(sf::RenderWindow* wnd);
	int getXPos();
	int getYpos();
	int getBaseXPos();
	int getBaseYPos();
	int getCompletion();
	void setXPos(int x);
	void setYPos(int y);
	void recall();
	void incrementCompletion(int value);
	void resetCompletion();

	string getName();
};