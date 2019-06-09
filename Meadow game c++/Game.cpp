#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}
void Game::initGame()
{
	char gameType;
	std::cout << "New game  -n\n";
	std::cout << "Load game -l\n";
	do
	{
		std::cin >> gameType;
	} while (gameType != 'n' && gameType != 'N' && gameType != 'l' && gameType != 'L');

	World* world;
	if (gameType == 'n' || gameType == 'N') //new game
	{
		int x, y;
		
		std::cout << "Board width:";
		do
		{
			bool aux = true;
			std::cin.exceptions(std::istream::failbit);
			do {
				try {
					std::cin >> x;
					aux = true;
				}
				catch (std::ios_base::failure &fail) {
					aux = false;
					std::cout << "Board size must be a numer" << std::endl;
					std::cin.clear();
					std::string tmp;
					getline(std::cin, tmp);
				}
			} while (aux == false);

		} while (x<MIN_BOARD_SIZE || x>MAX_BOARD_SIZE);

		std::cout << "Board height:";
		do
		{
			bool aux = true;
			std::cin.exceptions(std::istream::failbit);
			do {
				try {
					std::cin >> y;
					aux = true;
				}
				catch (std::ios_base::failure &fail) {
					aux = false;
					std::cout << "Board size must be a numer" << std::endl;
					std::cin.clear();
					std::string tmp;
					getline(std::cin, tmp);
				}
			} while (aux == false);

		} while (y<MIN_BOARD_SIZE || y>MAX_BOARD_SIZE);
			
		world = new World(x, y);
		world->initWorld(false);
	}
	else //load game
	{
		std::fstream file;
		file.open("save.txt", std::ios::in);
		if (file.good() == false)
		{
			exit(0);
		}
		int x, y, id, age, strength, n,turns;
		char sign;
		file >> x >> y >> turns>>n;
		world = new World(x, y,turns);
		for (int i = 0;i < n;i++)
		{
			file >> sign >> x >> y >> age >> id >> strength;
			world->importOrganism(sign, x, y, age, id, strength);
		}
		world->initWorld(true);
		
	}

	while (world->getHeight()*world->getWidth()!= world->organismsNumber())
	{
		world->makeTurn();
		input(*world);
	}
}

void Game::input(World& world)
{
	int c=0;
	c = _getch();
	if (c == 0xE0)
	{
		int c2 = _getch();
		world.setInput(c2);
	}
	else
	{
		switch (c)
		{
		case 's':
		case 'S':
			world.addTurnDescription("Game has been saved");
			world.exportOrganisms();
			break;
		case KEY_ESC:
			std::exit(0);
			break;
		}
		world.setInput(c);
	}

}
