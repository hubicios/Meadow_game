#pragma once
#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(World& world, const Point point);
	~Wolf();
	void breeding() override;
	std::string toString() override;
};
#endif /*WOLF_H */
