#include "Wolf.h"



Wolf::Wolf(World& world, const Point point)
	:Animal(world, point, SignEnum::WOLF_SIGN, WOLF_STRENGTH, WOLF_PRIORITY)
{
}


Wolf::~Wolf()
{
}
void Wolf::breeding()
{
	Point* freePlace = world_.randomFreePlace(*this);
	if (freePlace!=nullptr)
	{
		breedingDescription();
		world_.addOrganism(new Wolf(world_, *freePlace));
	}
}

std::string Wolf::toString()
{
	return "Wolf";
}
