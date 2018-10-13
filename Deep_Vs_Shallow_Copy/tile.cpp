#include <iostream>
#include "tile.h"

tile::tile()
{
}

tile::tile(const char* imageFilename)
{
	texture = LoadTexture(imageFilename);
}

tile::~tile()
{
}