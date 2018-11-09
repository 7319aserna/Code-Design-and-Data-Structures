#include "FallingFactory.h"
#include <stdlib.h>
#include <ctime>

SimpleSprite * FallingFactory::spriteMasters = NULL;
size_t FallingFactory::spriteCount = 0;

void FallingFactory::init()
{
	// Our FallingFactory class will need a way of loading in ...
	// various textures and creating it's sprite master's ...
	// array. The following is one example.
	spriteCount = 3;
	spriteMasters = new SimpleSprite[spriteCount];
	spriteMasters[0] = *(new SimpleSprite("Meteors/spaceMeteors_001.png", "Meteor", .1f));
	spriteMasters[1] = *(new SimpleSprite("Meteors/spaceMeteors_002.png", "Meteor", .1f));
	spriteMasters[2] = *(new SimpleSprite("Meteors/spaceMeteors_003.png", "Meteor", .1f));
}

SimpleSprite * FallingFactory::getRandom()
{
	SimpleSprite * temp = new SimpleSprite(spriteMasters[rand() % spriteCount]);

	temp->r2.x = rand() % 960;

	return temp;


	/*
	int spritePicker;
	srand(time(NULL));
	spritePicker = rand() % spriteCount - 1;
	
	// Make a new simpleSprite
	SimpleSprite * _SimpleSprite = new SimpleSprite;

	_SimpleSprite->rot = spriteMasters[spritePicker].rot;
	_SimpleSprite->texture = spriteMasters[spritePicker].texture;

	_SimpleSprite->r1.height = spriteMasters[spritePicker].r1.height;
	_SimpleSprite->r1.width = spriteMasters[spritePicker].r1.width;
	_SimpleSprite->r1.x = spriteMasters[spritePicker].r1.x;
	_SimpleSprite->r1.y = spriteMasters[spritePicker].r1.y;

	_SimpleSprite->r2.height = spriteMasters[spritePicker].r2.height;
	_SimpleSprite->r2.width = spriteMasters[spritePicker].r2.width;
	_SimpleSprite->r2.x = spriteMasters[spritePicker].r2.x;
	_SimpleSprite->r2.y = spriteMasters[spritePicker].r2.y;

	return _SimpleSprite;
	*/
}

SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
{
	SimpleSprite * hold = nullptr;
	int counter = 0;
	for (int i = 0; i < spriteCount; i++) {
		if (spriteMasters[i].sprType == _sprType) {
			SimpleSprite * temp = hold;
			counter++;
			hold = new SimpleSprite[counter];
			for (int j = 0; j < counter - 1; j++) {
				hold[j] = temp[j];
			}
			hold[counter - 1] = spriteMasters[i];
			delete[] temp;
		}
	}
	return &hold[rand() % counter];
/*
	SimpleSprite * _SimpleSprite = new SimpleSprite();
	_SimpleSprite->rot = spriteMasters[spritePicker].rot;
	_SimpleSprite->sprType = spriteMasters[spritePicker].sprType;
	_SimpleSprite->texture = spriteMasters[spritePicker].texture;

	_SimpleSprite->r1.height = spriteMasters[spritePicker].r1.height;
	_SimpleSprite->r1.width = spriteMasters[spritePicker].r1.width;
	_SimpleSprite->r1.x = spriteMasters[spritePicker].r1.x;
	_SimpleSprite->r1.y = spriteMasters[spritePicker].r1.y;

	_SimpleSprite->r2.height = spriteMasters[spritePicker].r2.height;
	_SimpleSprite->r2.width = spriteMasters[spritePicker].r2.width;
	_SimpleSprite->r2.x = spriteMasters[spritePicker].r2.x;
	_SimpleSprite->r2.y = spriteMasters[spritePicker].r2.y;
*/
}

FallingFactory::FallingFactory()
{
}

FallingFactory::~FallingFactory()
{
}
