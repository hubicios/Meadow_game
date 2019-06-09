#include "Belladonna.h"



Belladonna::Belladonna(World& world, Point& point)
	:Plant(world, point, SignEnum::BELLADONNA_SIGN, BELLADONNA_STRENGTH,BELLADONNA_SPREAD)
{
}

Belladonna::~Belladonna()
{
}

void Belladonna::collision(Organism& attacker)
{
	deadlyPlantEaten(attacker);
}
void Belladonna::spread()
{
	Point* freePlace = world_.randomFreePlace(*this);
	bool succes = freePlace != nullptr;
	if (succes&&isAlive_)
	{
		world_.addOrganism(new Belladonna(world_, *freePlace));
	}
	spreadDescription(succes);
}

std::string Belladonna::toString()
{
	return "Belladonna";
}
