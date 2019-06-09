#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include "Organism.h"

class Animal : public Organism
{
public:
	//Animal();
	Animal(World& world, const Point point, const char sign, const int strength, const int priority);
	~Animal();

	void action() override;

	void collision(Organism& attacker) override;
	virtual void breeding() = 0;
	void breedingDescription();
	virtual std::string toString();
	Direction randomDirection();// random direction of length 1
	Direction randomDirection(int n);//random direction of length n
	std::vector<int> allDirectionMixed();//all available directions randomized of length 1
	std::vector<int> allDirectionMixed(int n);//all available directions randomized of length n
	Point* newPoint(Direction direction);
	void move(Direction direction); //moves by 1 in direction
	void move(Direction direction, int n);//moves by n in direction
	bool isFightOff(Organism& attacker) override; //check if attack was 'bounced'

protected:
	bool attack(Organism* defender);
private:
};
#endif /* ANIMAL_H */
