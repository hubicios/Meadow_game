#include "Fox.h"



Fox::Fox(World& world, const Point point)
	:Animal(world, point, SignEnum::FOX_SIGN, FOX_STRENGTH, FOX_PRIORITY)
{
}


Fox::~Fox()
{
}
void Fox::action() //fox never steps on higher opponent
{
	checkLifespan();
	if (isAlive_&&age_ > 0)
	{
		std::vector<int> allDirections = allDirectionMixed();

		Point *new_point;
		Organism *field_taken;
		Direction newDirection;
		do
		{
			newDirection = (Direction)allDirections.back();
			new_point = newPoint(newDirection);
			allDirections.pop_back();
			field_taken = world_.fieldTaken(new_point);
		} while (allDirections.size() > 0 && field_taken != NULL && field_taken->getStrength() > strength_); //searches for free spot (if nothing is free, stays in the same filed)

		if (attack(field_taken))
		{
			move(newDirection);
		}
	}
	age_++;
}

void Fox::breeding()
{
	Point* freePlace = world_.randomFreePlace(*this);
	if (freePlace != nullptr)
	{
		breedingDescription();
		world_.addOrganism(new Fox(world_, *freePlace));
	}
}

std::string Fox::toString()
{
	return "Fox";
}
