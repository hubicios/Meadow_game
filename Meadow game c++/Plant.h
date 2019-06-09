#pragma once
#ifndef PLANT_H
#define PLANT_H
#include "Organism.h"
class Plant : public Organism
{
public:
	Plant(World& world, const Point point, const char sign, const int strength, const double spread);
	~Plant();

	double getSpread() const;
	void setSpread(const double spread);
	void action() override;
	void action(double chances);
	void collision(Organism& attacker) override;
	void deadlyPlantEaten(Organism& attacker);
	virtual void spread() = 0;
	void spreadDescription(bool succes);
	bool isFightOff(Organism& attacker) override;
	std::string toString() override;
protected:
	double spread_;
private:
};
#endif /* PLANT_H */
