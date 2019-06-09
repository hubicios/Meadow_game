#pragma once

//ANIMALS
#define FERTILITY_AGE 4 //min age to make new organizm
// breeding available with age>=4
#define LIFESPAN 50//animal with age>=50 (excluding human) dies

#define HUMAN_STRENGTH 5
#define HUMAN_PRIORITY 4
#define HUMAN_SIGN 'C'
#define HUMAN_SKILL_TIME 5

#define WOLF_STRENGTH 9
#define WOLF_PRIORITY 5
//#define WOLF_SIGN 'W'

#define SHEEP_STRENGTH 4
#define SHEEP_PRIORITY 4
//#define SHEEP_SIGN 'O'

#define FOX_STRENGTH 3
#define FOX_PRIORITY 7
//#define FOX_SIGN 'L'

#define TORTOISE_STRENGTH 2
#define TORTOISE_PRIORITY 1
//#define TORTOISE_SIGN 'Z'

#define ANTELOPE_STRENGTH 4
#define ANTELOPE_PRIORITY 4
//#define ANTELOPE_SIGN 'A'
#define ANTELOPE_JUMP 2

//PLANTS
#define GRASS_STRENGTH 0
#define GRASS_SPREAD 0.02
//#define GRASS_SIGN 't'

#define DANDELION_STRENGTH 0
#define DANDELION_SPREAD 0.02
#define DANDELION_SPREAD_TIMES 3
//#define DANDELION_SIGN 'm'

#define GUARANA_STRENGTH 0
#define GUARANA_SPREAD 0.02
#define GUARANA_BONUS_GIVEN 3
//#define GUARANA_SIGN 'g'

#define BELLADONNA_STRENGTH 99
#define BELLADONNA_SPREAD 0.03
//#define BELLADONNA_SIGN 'j'

#define SOSNOWSKIS_HOGWEED_STRENGTH 10
#define SOSNOWSKIS_HOGWEED_SPREAD 0.01
//#define SOSNOWSKIS_HOGWEED_SIGN 'b'

#define PLANT_SPREAD 0.02


namespace SignEnum
{
	enum Sign
	{
		WOLF_SIGN = 'W',
		SHEEP_SIGN = 'O',
		FOX_SIGN = 'L',
		TORTOISE_SIGN = 'Z',
		ANTELOPE_SIGN = 'A',
		GRASS_SIGN = 't',
		DANDELION_SIGN = 'm',
		GUARANA_SIGN = 'g',
		BELLADONNA_SIGN = 'j',
		SOSNOWSKIS_HOGWEED_SIGN = 'b',
		COUNT_SIGN = 10
	};

	static const char All[] = { WOLF_SIGN, SHEEP_SIGN, FOX_SIGN,TORTOISE_SIGN,ANTELOPE_SIGN ,GRASS_SIGN ,DANDELION_SIGN ,GUARANA_SIGN ,BELLADONNA_SIGN ,SOSNOWSKIS_HOGWEED_SIGN };
}

//KIERUNKI
enum Direction
{
	TOP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
	DIRECTION_NONE = 4
};

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

#define MAX_ALERTS_HEIGHT 20
#define MAX_BOARD_SIZE 50
#define MIN_BOARD_SIZE 10
#define POPULTION_DENISTY 2 // 1-low 2-medium 3-high