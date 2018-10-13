#include "wizard.h"
#include "raylib/raylib.h"

wizard::wizard()
{
	isWizardAlive = true;
	texture = LoadTexture("wizzart_m_run_anim_f2.png");
}

wizard::~wizard()
{
	UnloadTexture(texture);
}

void wizard::draw()
{
	DrawText(name, position.x - 62.5f, position.y - 10.0f, 20, BLACK);
	DrawTextureEx(texture, position, 0.0f, 3.0f, WHITE);
}

void wizard::update(float deltaTime)
{
	if (isWizardAlive) {
		if (IsKeyDown(KEY_W)) {
			position.y -= speed * deltaTime;
		}
		if (IsKeyDown(KEY_A)) {
			position.x -= speed * deltaTime;
		}
		if (IsKeyDown(KEY_S)) {
			position.y += speed * deltaTime;
		}
		if (IsKeyDown(KEY_D)) {
			position.x += speed * deltaTime;
		}
	}
}
