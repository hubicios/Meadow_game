#include "Organism.h"



int Organism::nOrganism = 0;

Organism::Organism(World& world,const Point point,const char sign,const int strength,const int priority)
	:world_(world),point_(point),sign_(sign),strength_(strength),priority_(priority),age_(0),isAlive_(true),id_(nOrganism)
{
	nOrganism++;
}

/*Organism::Organism()
{
}*/

Organism::~Organism()
{
}
void Organism::draw()
{
	if (isAlive_)
	{
		COORD coord = { point_.getX(), point_.getY() };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		std::cout << sign_;
		coord = { 1, (short)world_.getHeight() + 2 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
}
int Organism::getStrength() const
{
	return strength_;
}
void Organism::setStrength(const int strength)
{
	strength_ = strength;
}
void Organism::increaseStrength(const int add)
{
	strength_+=add;
}
int Organism::getPriority() const
{
	return priority_;
}
char Organism::getSign() const
{
	return sign_;
}
int Organism::getAge() const
{
	return age_;
}
void Organism::setAge(const int age)
{
	age_=age;
}
void Organism::increasAge()
{
	age_++;
}
int Organism::getId() const
{
	return id_;
}
void  Organism::setId(const int id)
{
	id_ = id;
}
bool Organism::getIsAlive() const
{
	return isAlive_;
}
void Organism::setIsAlive(const bool isAlive)
{
	isAlive_ = isAlive;
	if (isAlive_ == false)
	{
		point_.setXY(0, 0);
	}
}
void Organism::checkLifespan()
{
	if (age_ >= LIFESPAN)
	{
		isAlive_ = false;
	}
}
Point Organism::getPoint() const
{
	return point_;
}


/*std::ostream& operator << (std::ostream& os, const Organism& organizm)
{
	std::cout<< organizm.getPriority() << " -_- " <<organizm.getSign();
	return os;
}*/
