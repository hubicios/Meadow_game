#pragma once
#ifndef HUMAN_H
#define HUMAN_H

#include "Animal.h"
class Human : public Animal
{
public:
	//Human();
	Human(World& world, const Point point);
	~Human();
	int userInput();
	void action() override;
	void breeding() override;
	bool isFightOff(Organism& attacker) override;
	std::string toString() override;
	void draw() override;
private:
	int skillDuration_; //how long skill is active
	int skillCooldown_; //how long till skill will be available
};
#endif /*HUMAN_H */
