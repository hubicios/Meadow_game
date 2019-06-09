#include "Antelope.h"



Antelope::Antelope(World& world, const Point& point)
	:Animal(world, point, SignEnum::ANTELOPE_SIGN, ANTELOPE_STRENGTH, ANTELOPE_PRIORITY)
{
}


Antelope::~Antelope()
{
}

void Antelope::action() //moving range 2 field
{
	checkLifespan();
	if (isAlive_&&age_>0)
	{
		Direction new_direction = randomDirection(ANTELOPE_JUMP);
		Point *new_point = newPoint(new_direction);
		Organism *fieldTaken = world_.fieldTaken(new_point);

		if (attack(fieldTaken))
		{
			move(new_direction, ANTELOPE_JUMP);
		}
	}
	age_++;
}

void Antelope::collision(Organism& attacker) // 50% chances for escaping from fight
{
	if (rand() % 2 == 1)// antelope stays
	{
		if (strength_ < attacker.getStrength())
		{
			setIsAlive(false);
			world_.addTurnDescription(attacker.toString() + " killed ->" + this->toString());
		}
		else
		{
			attacker.setIsAlive(false);
			world_.addTurnDescription(attacker.toString() + " <- has been killed by " + this->toString());
		}
	}
	else //runs to nearest field
	{
		Point* freePlace = world_.randomFreePlace(*this);
		if (freePlace != nullptr)
		{
			point_.setXY(freePlace->getX(), freePlace->getY());
			world_.addTurnDescription(this->toString() + " has escaped from " + attacker.toString());
			delete freePlace;
		}
		else
		{
			collision(attacker);
		}
	}
}

std::string Antelope::toString()
{
	return "Antelope";
}

void Antelope::breeding()
{
	Point* freePlace = world_.randomFreePlace(*this);
	if (freePlace != nullptr)
	{
		breedingDescription();
		world_.addOrganism(new Antelope(world_, *freePlace));
	}
}