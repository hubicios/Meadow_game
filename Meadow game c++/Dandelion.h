#pragma once
#ifndef DANDELION_H
#define DANDELION_H

#include "Plant.h"
class Dandelion : public Plant
{
public:
	Dandelion(World & world, Point & point);
	~Dandelion();

	void action() override;
	void spread() override;
	std::string toString() override;
};
#endif /*DANDELION_H */

