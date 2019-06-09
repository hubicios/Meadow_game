#include "Guarana.h"



Guarana::Guarana(World& world, Point& point)
	:Plant(world, point, SignEnum::GUARANA_SIGN, GUARANA_STRENGTH, GUARANA_SPREAD)
{
}


Guarana::~Guarana()
{
}

void Guarana::collision(Organism& attacker)
{
	std::ostringstream oss;
	std::string str;
	attacker.increaseStrength(GUARANA_BONUS_GIVEN); //increase strenght by bonus (default 3)
	setIsAlive(false);
	oss << attacker.toString() << " strength is now " << attacker.getStrength()<<". "<< this->toString()<<" has been eaten";
	str = oss.str();
	world_.addTurnDescription(str);
}
void Guarana::spread()
{
	Point* freePlace = world_.randomFreePlace(*this);
	bool succes = freePlace != nullptr;
	if (succes&&isAlive_)
	{
		world_.addOrganism(new Guarana(world_, *freePlace));
	}
	spreadDescription(succes);
}

std::string Guarana::toString()
{
	return "Guarana";
}
