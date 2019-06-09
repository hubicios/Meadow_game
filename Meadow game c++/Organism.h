#pragma once
#ifndef ORGANISM_H
#define ORGANISM_H

#include "Point.h"
#include "Window.h"
#include "World.h"
#include "CONSTS.h"
#include <iostream>
#include <cstdio>      
#include <cstdlib>     
#include <ctime>       
#include <vector>  
#include <random>
#include <chrono>
#include <iostream>
#include <windows.h>
#include <conio.h>
//#include <string> 

class World; //forward declaration Organism<->World

class Organism
{
public:
	//Organism();
	Organism(World& world, const Point point, const char sign, const int strength, const int priority);
	~Organism();
	//virtual Organism* clone()=0;
	virtual std::string toString() = 0;
	virtual void action() = 0;
	virtual void collision(Organism& intruz) = 0;
	virtual bool isFightOff(Organism& attacker) = 0; //checks if attack was countered
	virtual void draw(); //draws organism's sign on screen

	int getStrength() const;
	void setStrength(const int strength);
	void increaseStrength(const int add);
	int getPriority() const;
	char getSign() const;
	int getAge() const;
	void setAge(const int age);
	void increasAge();
	int getId() const;
	void setId(const int id);
	bool getIsAlive() const;
	void setIsAlive(const bool isAlive);
	void checkLifespan();
	Point getPoint() const;

protected:
	int strength_;
	int priority_;
	char sign_;
	int age_;
	bool isAlive_;
	Point point_;
	int id_;
	static int nOrganism;

	World & world_;
	//friend std::ostream& operator << (std::ostream& os, const Organism& organizm);
private:
};
#endif /* ORGANISM_H */
