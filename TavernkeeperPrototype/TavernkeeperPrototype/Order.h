//feed in a string, thats the drink they made. Depending on the string fill in certain booleans that tell about that drink. Then compare it to what the order is asking.
#include <SFML\Graphics.hpp>
using namespace std;
class Order{
private:
	sf::RectangleShape* orderBackground;
	sf::Text* orderText;
	sf::Font* orderFont;
public:
	Order(int numberOf);
	void render(sf::RenderWindow* wnd);
	void createCard(string sOrder);
};