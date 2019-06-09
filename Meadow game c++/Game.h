#pragma once
#ifndef GAME_H
#define GAME_H

/*#include <vector> //using libraries
#include <queue>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <sstream>
#include <fstream>*/

#include "Window.h"
#include "World.h"
#include "Organism.h"

class Game
{
public:
	Game();
	~Game();
	void initGame();
	void input(World& world);
};
#endif /* GAME_H */
