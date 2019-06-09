#pragma once
#ifndef sHEEP_H
#define SHEEP_H

#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(World& world, const Point point);
	~Sheep();
	void breeding() override;
	std::string toString() override;
};
#endif /*SHEEP_H */
