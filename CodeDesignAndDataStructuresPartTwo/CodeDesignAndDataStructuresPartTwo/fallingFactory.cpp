#include <ctime>
#include "fallingFactory.h"
#include <stdlib.h>

simpleSprite * fallingFactory::spriteMasters = NULL;
size_t fallingFactory::spriteCount = 0;

void fallingFactory::init()
{
	// Our fallingFactory class will need a way of loading in ...
	// various textures and creating it's sprite master's ...
	// array. The following is one example.
	spriteCount = 3;
	spriteMasters = new simpleSprite[spriteCount];
	spriteMasters[0] = *(new simpleSprite("Meteors/spaceMeteors_001.png", "Meteor", .1f));
	spriteMasters[1] = *(new simpleSprite("Meteors/spaceMeteors_002.png", "Meteor", .1f));
	spriteMasters[2] = *(new simpleSprite("Meteors/spaceMeteors_003.png", "Meteor", .1f));
}

simpleSprite * fallingFactory::getRandom()
{
	simpleSprite * temp = new simpleSprite(spriteMasters[rand() % spriteCount]);

	temp->r2.x = rand() % 960;

	return temp;
}

simpleSprite * fallingFactory::getFromType(const std::string & _sprType)
{
	simpleSprite * hold = nullptr;
	int counter = 0;
	for (int i = 0; i < spriteCount; i++) {
		if (spriteMasters[i].sprType == _sprType) {
			simpleSprite * temp = hold;
			counter++;
			hold = new simpleSprite[counter];
			for (int j = 0; j < counter - 1; j++) {
				hold[j] = temp[j];
			}
			hold[counter - 1] = spriteMasters[i];
			delete[] temp;
		}
	}
	return &hold[rand() % counter];
}

fallingFactory::fallingFactory() {
}

fallingFactory::~fallingFactory() {
}
