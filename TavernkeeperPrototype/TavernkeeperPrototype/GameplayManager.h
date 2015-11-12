#include "SFML\Graphics.hpp"
class GameplayManager{
private: 
	bool isPouring;
	bool isPeeling;
public:
	GameplayManager();
	void togglePouring();
	void togglePeeling();
	void gameCheck();

	bool getPouring();
	bool getPeeling();
};