#include "mapCreator.h"

mapCreator::mapCreator()
{
}

mapCreator::mapCreator(const char * imageFilename)
{
	texture = LoadTexture(imageFilename);
}

mapCreator::~mapCreator()
{
	//UnloadTexture(texture);
}

void mapCreator::update(float deltaTime, int screenWidth, int screenHeight)
{
	SetWindowSize(755, 1255);
	SetWindowPosition(50, 50);

	mapCreator apshalt_Road_01("PNG/Tiles/Asphalt road/road_asphalt01.png");
	mapCreator apshalt_Road_02("PNG/Tiles/Asphalt road/road_asphalt02.png");
	mapCreator apshalt_Road_03("PNG/Tiles/Asphalt road/road_asphalt03.png");
	mapCreator apshalt_Road_04("PNG/Tiles/Asphalt road/road_asphalt05.png");
	mapCreator apshalt_Road_05("PNG/Tiles/Asphalt road/road_asphalt39.png");
	mapCreator apshalt_Road_06("PNG/Tiles/Asphalt road/road_asphalt41.png");
	mapCreator apshalt_Road_07("PNG/Tiles/Asphalt road/road_asphalt42.png");
	mapCreator land_grass01("PNG/Tiles/Grass/land_grass04.png");

	// Use the mapCreator class to make a new array which will then store...
	// ... the types of tiles there are.
	mapCreator tileTypes[8];
	tileTypes[0] = apshalt_Road_01;
	tileTypes[1] = apshalt_Road_02;
	tileTypes[2] = apshalt_Road_03;
	tileTypes[3] = apshalt_Road_04;
	tileTypes[4] = apshalt_Road_05;
	tileTypes[5] = apshalt_Road_06;
	tileTypes[6] = apshalt_Road_07;
	tileTypes[7] = land_grass01;

	// You then make a new int array (grid) which will have positions...
	// ... to put your textures into it.
	int grid[3][5];
	grid[0][0] = 2;
	grid[1][0] = 1;
	grid[2][0] = 3;

	grid[0][1] = 0;
	grid[1][1] = 7;
	grid[2][1] = 0;

	grid[0][2] = 0;
	grid[1][2] = 7;
	grid[2][2] = 6;

	grid[0][3] = 0;
	grid[1][3] = 7;
	grid[2][3] = 0;

	grid[0][4] = 4;
	grid[1][4] = 1;
	grid[2][4] = 5;

	// The starter cell's x position
	float cellPositionX = 0.0f;

	// The starter cell's y position
	float cellPositionY = 0.0f;

	// This would iterate through each cell (Column)
	for (int s = 0; s < 3; s++) {

		// Then it would iterate through each row
		for (int j = 0; j < 5; j++) {
			DrawTextureEx(tileTypes[grid[s][j]].texture, { cellPositionY, cellPositionX }, 0.0f, 2.0f, WHITE);

			cellPositionX += 250;
		}

		cellPositionX = 0;
		cellPositionY += 250;
	}
}