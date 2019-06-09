#include "Tortoise.h"



Tortoise::Tortoise(World& world, const Point point)
	:Animal(world, point, SignEnum::TORTOISE_SIGN, TORTOISE_STRENGTH, TORTOISE_PRIORITY)
{
}


Tortoise::~Tortoise()
{
}
void Tortoise::action()
{
	checkLifespan();
	if (age_ > 0 && rand() % 4 == 0)
	{
		Animal::action();
	}
	else
	{
		age_++;
	}
}
void Tortoise::collision(Organism& attacker)
{
	Animal::collision(attacker);
}
bool Tortoise::isFightOff(Organism& attacker)
{
	return (attacker.getStrength() < 5);

}
std::string Tortoise::toString()
{
	return "Tortoise";
}
void Tortoise::breeding()
{
	Point* freePlace = world_.randomFreePlace(*this);
	if (freePlace != nullptr)
	{
		breedingDescription();
		world_.addOrganism(new Tortoise(world_, *freePlace));
	}
}