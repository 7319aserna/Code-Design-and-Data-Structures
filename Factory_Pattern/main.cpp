#include <iostream>
#include <string> 
#include "Libaries.h"
#include <vector>

// And here is our calling code inside our main.
int main() {
	/*
	IBox* p = NULL;
	IFactory* f = NULL;
	f = new Factory();
	p = f->create("Red");
	std::cout << "\nColor is: " << p->color() << "\n";
	delete p;
	p = f->create("Blue");
	std::cout << "\nColor is: " << p->color() << "\n";
	delete p;
	return 1;
	*/
	int screenWidth = 960;
	int screenHeight = 540;

	InitWindow(screenWidth, screenHeight, "Factory Pattern");
	SetTargetFPS(60);
	
	FallingFactory::init();
	SimpleSprite simpleSpriteObject = *FallingFactory::getRandom();

	simpleSpriteObject.pos = { 250, 0 };

	std::vector<SimpleSprite *> spritesOrSomething;
	spritesOrSomething.push_back(FallingFactory::getRandom());
	spritesOrSomething.push_back(FallingFactory::getRandom());
	spritesOrSomething.push_back(FallingFactory::getRandom());
	spritesOrSomething.push_back(FallingFactory::getRandom());

	while (!WindowShouldClose()) {

		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (int i = 0; i < spritesOrSomething.size(); i++) {
			spritesOrSomething[i]->translate({ 0, 10 });
			spritesOrSomething[i]->draw();
			
			if (spritesOrSomething[i]->r2.y > screenHeight) {
				spritesOrSomething[i]->r2.y = 0;
				spritesOrSomething[i]->r2.x = rand() % 960;

			}
		}

		if (IsKeyPressed(KEY_Q)) {
			spritesOrSomething.push_back(FallingFactory::getRandom());
		}

		/*simpleSpriteObject.translate({0, 10});

		simpleSpriteObject.draw();*/

		EndDrawing();
	}
}