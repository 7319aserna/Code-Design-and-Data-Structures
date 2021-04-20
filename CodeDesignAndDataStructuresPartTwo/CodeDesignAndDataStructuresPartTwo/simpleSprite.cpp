#include "simpleSprite.h"
#include "raylib.h"

void simpleSprite::translate(Vector2 delta) {
	// In the main, I would need to have a while loop, and...
	// during the loop, the sprite will continue to move in that...
	// direction.
	r2.x = r2.x + delta.x;
	r2.y = r2.y + delta.y;
}

void simpleSprite::draw() {
	DrawTexturePro(texture, r1, r2, { 0, 0 }, rot, WHITE);
}

simpleSprite::simpleSprite() {
}

simpleSprite::simpleSprite(const std::string & _filename, const std::string _sprType, float _scale) {
	// When converting from a std::string to a const char...
	// at the end of the name, add (.c_str())
	texture = LoadTexture(_filename.c_str());
	r1 = Rectangle{ 0, 0, (float)(texture.width), (float)(texture.height) };
	r2 = Rectangle{ 0, 0, r1.width * _scale, r1.height * _scale };
	pos = { 0, 0 };
	rot = 0.0f;
	sprType = _sprType;
}

simpleSprite * simpleSprite::Clone() {
	// Returns new instance of class
	// new instance based on currtent object being cloned
	return new simpleSprite(*this);
}
