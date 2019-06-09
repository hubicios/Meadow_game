#include "Sheep.h"



Sheep::Sheep(World& world, const Point point)
	:Animal(world,point, SignEnum::SHEEP_SIGN,SHEEP_STRENGTH,SHEEP_PRIORITY)
{
}


Sheep::~Sheep()
{
}
void Sheep::breeding()
{
	Point* freePlace = world_.randomFreePlace(*this);
	if (freePlace != nullptr)
	{
		breedingDescription();
		//Organism* temp = new Sheep(world_, *freePlace);
		world_.addOrganism(new Sheep(world_, *freePlace));
	}
}

std::string Sheep::toString()
{
	return "Sheep";
}
