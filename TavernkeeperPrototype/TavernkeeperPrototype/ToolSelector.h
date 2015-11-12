#include <SFML\Graphics.hpp>
#include <vector>
#include <stdio.h>
#include "Tool.h"
using namespace std;
class ToolSelector{
private:
	typedef vector<Tool*> tVec;
	tVec* toolVector;
	int position;
public:
	ToolSelector();
	void render(sf::RenderWindow* wnd);
	void incrementTool();
	void decrementTool();
	void raiseTool();
	void lowerTool();
	void choose();

	tVec* getTVector();

	int getPosition();
};