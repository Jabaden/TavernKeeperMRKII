#include "ToolSelector.h"
ToolSelector::ToolSelector(){
	//bigg jig, little jig, spoon, peeler, knife
	this->toolVector = new tVec();
	int position = 0;
	Tool* tool = new Tool(200, 1080 - 200, "Big Jigger");
	Tool* tool1 = new Tool(325, 1080 - 200, "Little Jigger");
	Tool* tool2 = new Tool(450, 1080 - 200, "Spoon");
	Tool* tool3 = new Tool(575, 1080 - 200, "Peeler");
	Tool* tool4 = new Tool(700, 1080 - 200, "Knife");

	toolVector->push_back(tool);
	toolVector->push_back(tool1);
	toolVector->push_back(tool2);
	toolVector->push_back(tool3);
	toolVector->push_back(tool4);

}

void ToolSelector::render(sf::RenderWindow* wnd){
	for (auto iter = this->toolVector->begin(); iter != this->toolVector->end(); iter++){
		(*iter)->render(wnd);
	}
}

void ToolSelector::incrementTool(){
	this->position++;
	if (this->position > 4){
		this->position = 0;
	}
}

void ToolSelector::decrementTool(){
	this->position--;
	if (this->position < 0){
		this->position = 4;
	}
}

void ToolSelector::raiseTool(){
	Tool* tempTool = (this->toolVector->at(this->position));
	Tool* tempToolLeft;
	Tool* tempToolRight;
	if (this->position == 0){
		tempToolLeft = (this->toolVector->at(4));
	}
	else{
		tempToolLeft = this->toolVector->at((this->position) - 1);
	}

	if (this->position == 4){
		tempToolRight = this->toolVector->at(0);
	}
	else{
		tempToolRight = this->toolVector->at((this->position) + 1);
	}

	tempTool->setYPos(tempTool->getYpos() - 100);
	//tempToolLeft->setYPos(tempToolLeft->getBaseYPos());
	//tempToolRight->setYPos(tempToolRight->getBaseYPos());

	tempToolLeft->recall();
	tempToolRight->recall();

}

void ToolSelector::choose(){
	Tool* chosenTool = (this->toolVector->at(this->position));
	chosenTool->setXPos(850);
	chosenTool->setYPos(500);
}

ToolSelector::tVec* ToolSelector::getTVector(){
	return this->toolVector;
}

int ToolSelector::getPosition(){
	return this->position;
}
