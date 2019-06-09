#pragma once
#ifndef BELLADONNA_H
#define BELLADONNA_H

#include "Plant.h"
class Belladonna : public Plant
{
public:
	Belladonna(World & world, Point & point);
	~Belladonna();
	void collision(Organism &intruz) override;
	void spread() override;
	std::string toString() override;
};
#endif /*BELLADONNA_H */