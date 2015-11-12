#include <SFML\Graphics.hpp>
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
	string name;

public:
	Tool(int xPos, int yPos, string name);
	sf::Sprite* getSprite();
	void render(sf::RenderWindow* wnd);
	int getXPos();
	int getYpos();
	int getBaseXPos();
	int getBaseYPos();
	void setXPos(int x);
	void setYPos(int y);
	void recall();

	string getName();
};