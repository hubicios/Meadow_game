#include "SosnowskisHogweed.h"



SosnowskisHogweed::SosnowskisHogweed(World& world,Point& point)
	:Plant(world, point, SignEnum::SOSNOWSKIS_HOGWEED_SIGN, SOSNOWSKIS_HOGWEED_STRENGTH,SOSNOWSKIS_HOGWEED_SPREAD)
{
}


SosnowskisHogweed::~SosnowskisHogweed()
{
}

void SosnowskisHogweed::action()
{
	std::vector<Organism*> neighbours = world_.neighbours(*this);
	for (int i = 0; i < neighbours.size(); i++)
	{
		if (neighbours[i]->getSign() != this->getSign())
		{
			neighbours[i]->setIsAlive(false);
			world_.addTurnDescription(this->toString() + " killed ->" + neighbours[i]->toString());
		}
	}
	age_++;
	Plant::action(SOSNOWSKIS_HOGWEED_SPREAD);

}
void SosnowskisHogweed::collision(Organism& attacker)
{
	deadlyPlantEaten(attacker);
}
std::string SosnowskisHogweed::toString()
{
	return "Sosnowski's hogweed";
}
void SosnowskisHogweed::spread()
{
	Point* freePlace = world_.randomFreePlace(*this);
	bool succes = freePlace != nullptr;
	if (succes&&isAlive_)
	{
		world_.addOrganism(new SosnowskisHogweed(world_, *freePlace));
	}
	spreadDescription(succes);
}