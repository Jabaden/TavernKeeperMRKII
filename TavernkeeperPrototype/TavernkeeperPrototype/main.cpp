#include <SFML/Graphics.hpp>
#include "DrinkDeck.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <time.h>
#include "Comparer.h"
//#include "GameVariables.h"
using namespace std;
int main()
{
	std::srand(unsigned(std::time(0)));
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	string testArray[2];
	testArray[0] = "test1";
	testArray[1] = "test2";
	DrinkCard testCard("ayy", "lmao", testArray);
	sf::Clock testClock;
	DrinkDeck* test = new DrinkDeck();
	test->shuffleDeck();
	test->drawCard();

	GameplayManager* gameplayManager = new GameplayManager();

	Comparer* comparer = new Comparer();

	//Drink* testDrink9 = new Drink(100,100);
	//int hello = testDrink9->getYpos();

	DrinkSelector* drinkSelectorTest = new DrinkSelector();
	drinkSelectorTest->incrementDrink();
	drinkSelectorTest->raiseDrink();
	drinkSelectorTest->choose();

	ToolSelector* toolSelectorTest = new ToolSelector();
	toolSelectorTest->incrementTool();
	toolSelectorTest->raiseTool();
	toolSelectorTest->choose();

	//FILE I/O 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Right){
					if (gameplayManager->getPouring() == false){
						drinkSelectorTest->incrementDrink();
						drinkSelectorTest->raiseDrink();
					}
				}
				if (event.key.code == sf::Keyboard::Left){
					if (gameplayManager->getPouring() == false){
						drinkSelectorTest->decrementDrink();
						drinkSelectorTest->raiseDrink();
					}
					else{
						Drink* rotateDrink = drinkSelectorTest->getDVector()->at(drinkSelectorTest->getPosition());
					}
				}
				if (event.key.code == sf::Keyboard::A){
					toolSelectorTest->decrementTool();
					toolSelectorTest->raiseTool();
				}
				if (event.key.code == sf::Keyboard::D){
					toolSelectorTest->incrementTool();
					toolSelectorTest->raiseTool();
				}
				if (event.key.code == sf::Keyboard::Space){
					toolSelectorTest->choose();
					drinkSelectorTest->choose();
					comparer->compareHands(toolSelectorTest, drinkSelectorTest, gameplayManager);
				}
			}
		}
		if (testClock.getElapsedTime().asSeconds() > 2){
			testClock.restart();
			//testCard.pickRandomAttribute();
		}
		window.clear(sf::Color::White);
		//testDrink->render(&window);
		//testDrink9->render(&window);
		toolSelectorTest->render(&window);
		drinkSelectorTest->render(&window);
		window.display();
	}

	return 0;
}