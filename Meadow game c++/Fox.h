#pragma once
#ifndef FOX_H
#define FOX_H

#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(World& world, const Point point);
	~Fox();

	void action() override;
	void breeding() override;
	std::string toString() override;
};
#endif /*FOX_H */
