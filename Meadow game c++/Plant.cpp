#include "Plant.h"



Plant::Plant(World& world, const Point point, const char sign, const int strength, const double spread)
	:Organism(world, point, sign, strength, 0), spread_(spread)
{
}


Plant::~Plant()
{
}

void Plant::action()
{
	//if ((double)rand() / RAND_MAX < spread_)
	if(rand()%1000< spread_*1000&&age_>=FERTILITY_AGE)
	{
		spread();
	}
	age_++;
}
void Plant::action(double chances)
{
	//if ((double)rand() / RAND_MAX < spread_)
	if (rand() % 1000 < chances*1000 && age_ >= FERTILITY_AGE)
	{
		spread();
	}
	age_++;
}
void Plant::spreadDescription(bool succes)
{
	if (succes == true)
	{
		world_.addTurnDescription(this->toString() + " made new plant");
	}
	/*else
	{
		world_.addTurnDescription(this->toString() + " failed making new plant");
	}*/
}
void Plant::collision(Organism& attacker)
{
	setIsAlive(false);
	world_.addTurnDescription(attacker.toString()+" destroyed "+this->toString()+" by stepping on it");
}

double Plant::getSpread() const
{
	return spread_;
}
void Plant::setSpread(const double spread)
{
	spread_ = spread;
}

bool Plant::isFightOff(Organism& attacker)
{
	return false;
}
std::string Plant::toString()
{
	return "Plant";
}
void Plant::deadlyPlantEaten(Organism& attacker)
{
	setIsAlive(false);
	if (strength_ > attacker.getStrength())
	{
		attacker.setIsAlive(false);
		world_.addTurnDescription(attacker.toString()+" killed himself by eating " + this->toString());
	}
	else
	{
		world_.addTurnDescription(attacker.toString() + " has eaten " + this->toString() + " but manage to survive");
	}

	
}