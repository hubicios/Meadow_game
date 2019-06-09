#include "Dandelion.h"



Dandelion::Dandelion(World & world, Point & point)
	:Plant(world, point, SignEnum::DANDELION_SIGN, DANDELION_STRENGTH,DANDELION_SPREAD)
{
}


Dandelion::~Dandelion()
{
}

void Dandelion::action()
{
	for (int i = 0;i < DANDELION_SPREAD_TIMES;i++)
	{
		Plant::action(DANDELION_SPREAD);
	}
	age_ = age_ - DANDELION_SPREAD_TIMES + 1;
}
void Dandelion::spread()
{
	Point* freePlace = world_.randomFreePlace(*this);
	bool succes = freePlace != nullptr;
	if (succes&&isAlive_)
	{
		world_.addOrganism(new Dandelion(world_, *freePlace));
	}
	spreadDescription(succes);
}

std::string Dandelion::toString()
{
	return "Dandelion";
}
