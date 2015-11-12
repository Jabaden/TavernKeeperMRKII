#include "GameplayManager.h"

GameplayManager::GameplayManager(){
	this->isPouring = false;
	this->isPouring = false;
}

void GameplayManager::togglePouring(){
	if (this->isPouring){
		this->isPouring = false;
	}
	else{
		this->isPouring = true;
	}
}

void GameplayManager::togglePeeling(){
	if (this->isPeeling){
		this->isPeeling = false;
	}
	else{
		this->isPeeling = true;
	}
}
//check if any boolean values are true. If so, start the minigame. 
void GameplayManager::gameCheck(){

}

bool GameplayManager::getPeeling(){
	return this->isPeeling;
}

bool GameplayManager::getPouring(){
	return this->isPouring;
}