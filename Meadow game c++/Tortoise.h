#pragma once
#ifndef TORTOISE_H
#define TORTOISE_H

#include "Animal.h"
class Tortoise : public Animal
{
public:
	Tortoise(World& world, const Point point);
	~Tortoise();

	void action() override;
	void collision(Organism& intruz) override;
	void breeding() override;
	bool isFightOff(Organism& attacker) override;
	std::string toString() override;
};
#endif /*TORTOISE_H */

