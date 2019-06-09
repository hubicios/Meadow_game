#pragma once
#ifndef GUARANA_H
#define GUARANA_H

#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(World & world, Point & point);
	~Guarana();

	void collision(Organism &intruz) override;
	void spread() override;
	std::string toString() override;
};
#endif /*GUARANA_H */
