#pragma once
#ifndef GRASS_H
#define GRASS_H

#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(World & world, Point & point);
	~Grass();
	void spread() override;
	std::string toString() override;
};
#endif /*GRASS_H */

