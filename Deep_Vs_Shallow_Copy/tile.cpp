#include <iostream>
#include "tile.h"

tile::tile()
{
	//texture = LoadTexture("mappack/PNG/mapTile_035.png");
}

tile::tile(const char* imageFilename)
{
	texture = LoadTexture(imageFilename);

}

tile::~tile()
{
}