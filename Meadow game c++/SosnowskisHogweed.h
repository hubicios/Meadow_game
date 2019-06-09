#pragma once
#ifndef SOSNOWSKISHOGWEED_H
#define SOSNOWSKISHOGWEED_H

#include "Plant.h"
class SosnowskisHogweed : public Plant
{
public:
	SosnowskisHogweed(World & world, Point & point);
	~SosnowskisHogweed();

	void action() override;
	void spread() override;
	void collision(Organism &attacker) override;
	std::string toString() override;
};
#endif /*SOSNOWSKISHOGWEED_H */

