#include "Animal.h"


/*Animal::Animal()
{
}*/
Animal::Animal(World& world, const Point point, const char sign, const int strength, const int priority)
	:Organism(world, point, sign, strength, priority)
{
}

Animal::~Animal()
{
}

void Animal::action()
{
	if (age_ == 0)
	{
		age_++;
	}
	else if(isAlive_)
	{
		age_++;
		Direction direction = randomDirection();
		Point *point = newPoint(direction);
		Organism *fieldTaken = world_.fieldTaken(point);
		if (attack(fieldTaken))
		{
			move(direction);
		}
	}
}

void Animal::collision(Organism& attacker)
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
bool Animal::attack(Organism* defender)
{
	bool makeMove = true;
	if (defender != NULL) //pole bylo zajete
	{
		if (sign_ == defender->getSign())
		{
			makeMove = false;
			if (age_ >= FERTILITY_AGE && defender->getAge() >= FERTILITY_AGE)
			{
				breeding();
			}
		}
		else if (defender->isFightOff(*this) == true)
		{
			world_.addTurnDescription(defender->toString() + " has fight off " + this->toString());
			makeMove = false;
		}
		else
		{
			defender->collision(*this);
			if (isAlive_ == false)
			{
				makeMove = false;
			}
		}
	}
	return makeMove;
}

void Animal::breedingDescription()
{
	world_.addTurnDescription("New " + this->toString() + " has been born");
}
std::string Animal::toString()
{
	return "Animal";
}
bool Animal::isFightOff(Organism& attacker)
{
	return false;
}
Direction Animal::randomDirection()
{
	return randomDirection(1);
}
Direction Animal::randomDirection(int n)
{
	std::vector<int> directionAvailabe = allDirectionMixed(n);
	if (directionAvailabe.size() > 0)
	{
		return (Direction)directionAvailabe.front();
	}
	else
	{
		return DIRECTION_NONE;
	}
}

std::vector<int> Animal::allDirectionMixed(int n)
{
	int x = point_.getX();
	int y = point_.getY();
	std::vector<int> directionAvailabe;
	if (x + n <= world_.getWidth())//RIGHT
	{
		directionAvailabe.push_back(RIGHT);
	}
	if (x - n >= 1)//LEFT
	{
		directionAvailabe.push_back(LEFT);
	}
	if (y - n >= 1)//TOP
	{
		directionAvailabe.push_back(TOP);
	}
	if (y + n <= world_.getHeight())//DOWN
	{
		directionAvailabe.push_back(DOWN);
	}
	//mixing
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(directionAvailabe.begin(), directionAvailabe.end(), std::default_random_engine(seed));

	return  directionAvailabe;
}
std::vector<int> Animal::allDirectionMixed()
{
	return allDirectionMixed(1);
}
Point* Animal::newPoint(Direction direction)
{
	Point* point = new Point();
	int x = point_.getX();
	int y = point_.getY();

	point->setX(x);
	point->setY(y);
	if (direction == RIGHT)
	{
		point->setX(x + 1);
	}
	else if (direction == LEFT)
	{
		point->setX(x - 1);
	}
	else if (direction == TOP)
	{
		point->setY(y - 1);
	}
	else if (direction == DOWN)
	{
		point->setY(y + 1);
	}
	return point;
}
void Animal::move(Direction direction)
{
	move(direction, 1);
}
void Animal::move(Direction direction, int n)
{
	int x = point_.getX();
	int y = point_.getY();
	if (direction == RIGHT)
	{
		point_.setX(x + n);
	}
	else if (direction == LEFT)
	{
		point_.setX(x - n);
	}
	else if (direction == TOP)
	{
		point_.setY(y - n);
	}
	else if (direction == DOWN)
	{
		point_.setY(y + n);
	}
}