#include "Game.h"
#include <iostream>

int main()
{
	Game* newGame = new Game();
	newGame->initGame();
	delete newGame;

	return 0;
}