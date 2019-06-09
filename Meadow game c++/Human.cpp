#include "Human.h"

#include <iostream>
#include <windows.h>
#include <conio.h>

/*Human::Human()
{
}*/
Human::Human(World& world, const Point point)
	:Animal(world, point, HUMAN_SIGN, HUMAN_STRENGTH, HUMAN_PRIORITY), skillCooldown_(0), skillDuration_(0)
{
}

Human::~Human()
{
}
void Human::action()
{
	if (isAlive_&&age_ > 0)
	{
		int input = userInput();
		if (input <= LEFT && input >= TOP)// poruszanie sie za pomoc¹ strza³ek
		{
			if (isAlive_)
			{
				Point *point = newPoint(Direction(input));
				Organism *fieldTaken = world_.fieldTaken(point);

				if (attack(fieldTaken))
				{
					move(Direction(input));
				}
			}
		}
		if (skillCooldown_ > 0)
		{
			skillCooldown_--;
		}
		if (skillDuration_ > 0)
		{
			skillDuration_--;
		}
	}
	age_++;
}
void Human::breeding()
{
	;
}
bool Human::isFightOff(Organism& attacker)
{
	return (skillDuration_ > 0); //skill is active
}

std::string Human::toString()
{
	return "Human";
}

void Human::draw()
{
	if(skillCooldown_==0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	else if(skillDuration_>0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	Organism::draw();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int Human::userInput()
{
	int c = world_.getInput();
	int n = 1;//moving distance
	bool correctInput = false;
	int returnValue = -1;
	std::ostringstream oss;
	std::string str = "";
	while (correctInput == false)
	{
		if (c == 0)
		{
			c = _getch();
		}
		switch (c)
		{
		case KEY_UP:
			if (point_.getY() - n >= 1)//TOP
			{
				returnValue = TOP;
				correctInput = true;
			}
			else
			{
				str = "End of the board";
				correctInput = false;
			}

			break;
		case KEY_DOWN:
			if (point_.getY() + n <= world_.getHeight())//DOWN
			{
				returnValue = DOWN;
				correctInput = true;
			}
			else
			{
				str = "End of the board";
			}

			break;
		case KEY_LEFT:
			if (point_.getX() - n >= 1)//LEFT
			{
				returnValue = LEFT;
				correctInput = true;
			}
			else
			{
				str = "End of the board";
			}
			break;
		case KEY_RIGHT:
			if (point_.getX() + n <= world_.getWidth())//RIGHT
			{
				returnValue = RIGHT;
				correctInput = true;
			}
			else
			{
				str = "End of the board";
			}
			break;
		case 'q':
			if (skillCooldown_ == 0)
			{
				skillCooldown_ = HUMAN_SKILL_TIME * 2;
				skillDuration_ = HUMAN_SKILL_TIME;

				oss << "Alzur's shield has been activated for " << skillDuration_ << " turns";
				str = oss.str();
				returnValue = 'q';
				correctInput = true;
			}
			else
			{
				if (skillDuration_ == 0)
				{
					oss << "Skill will be available after " << skillCooldown_ << " turns";
					str = oss.str();
				}
				else
				{
					oss << "Skill is still active for " << skillDuration_ << " rounds";
					str = oss.str();
				}
			}
			break;
		case 's':
			world_.exportOrganisms();
			break;
		case KEY_ESC:
			returnValue = c;
			correctInput = true;
			break;
		}
		c = 0;
	}
	if (str != "")
	{
		world_.addTurnDescription(str);
	}
	return returnValue;
}
