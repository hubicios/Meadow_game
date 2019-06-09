#pragma once
#ifndef ANTELOPE_H
#define ANTELOPE_H

#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(World& world, const Point& point);
	~Antelope();

	void action() override;
	void breeding() override;
	void collision(Organism& attacker) override;
	std::string toString() override;
};
#endif /*ANTELOPE_H */
