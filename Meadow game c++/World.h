#pragma once
#ifndef WORLD_H
#define WORLD_H


#include "Organism.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

class Organism; //forward declaration World potrzebuje Organism do vectora

class World
{
public:
	World();
	World(int width, int height);
	World(int width, int height, int turnCount);
	~World();
	void initWorld(bool exist);
	void makeTurn();
	void drawWorld();
	void sortOrganisms();// sorts organisms ,prepare for new turn
	void importOrganism(const char sign, const int x, const int y, const int age, const int id, const int strength);
	void exportOrganisms();
	void generateOrganisms();
	void generateOrganism(Point& point, char species);
	void addOrganism(Organism* organism);
	void deleteOrganisms();
	void showOrganisms();
	int organismsNumber() const;
	std::vector<Organism*> neighbours(Organism& organism);
	int neighboursNumer(Organism& organism);
	Point* randomFreePlace(Organism& organism); //free fields around organism
	Organism* fieldTaken(Point* point); //zwraca organizm na polu jezeli jest zajete
	bool fieldFree(int x, int y); //zwraca organizm na polu jezeli jest zajete
	void endGame();
	int getInput() const;
	void setInput(const int input);
	int getWidth() const;
	int getHeight() const;
	void addTurnDescription(std::string str);
	void showTurnDescription();
	void clearTurnDescription();
protected:
	friend std::ostream& operator << (std::ostream& os, const Organism& organizm);
private:
	std::vector<Organism*> organisms;
	Window* window_;
	int width_, height_; // <1 , width_/heigh_> closed interval
	int input_, turnCount_;
	std::queue<std::string> turnDescription_;

};
#endif /* WORLD_H */
