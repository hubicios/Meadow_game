#include "Grass.h"



Grass::Grass(World & world, Point & point)
	:Plant(world, point, SignEnum::GRASS_SIGN, GRASS_STRENGTH,GRASS_SPREAD)
{
}

Grass::~Grass()
{
}
void Grass::spread()
{
	Point* freePlace = world_.randomFreePlace(*this);
	bool succes = freePlace != nullptr;
	if (succes&&isAlive_)
	{
		world_.addOrganism(new Grass(world_, *freePlace));
	}
	spreadDescription(succes);;
}

std::string Grass::toString()
{
	return "Grass";
}
