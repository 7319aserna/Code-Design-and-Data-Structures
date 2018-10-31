#include <chrono>
#include "raylib/raylib.h"
#include <thread>
#include "wizard.h"

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
	DrawTextureEx(texture, position, rotation, 3.0f, WHITE);
	
	if (wPObject.projectileSpawned == true) {
		wPObject.draw();
	}
}

void wizard::update(float deltaTime)
{
	if (isWizardAlive) {
		wPObject.update(deltaTime);

		// Wizard Movement
		if (IsKeyDown(KEY_W)) {
			position.y -= speed * deltaTime;
			/*wPObject.projectilePosition.x = position.x + 50;
			wPObject.projectilePosition.y = position.y + 50;*/
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
		
		//// Wizard Attack
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
			wPObject.projectileSpawned = true;

			wPObject.projectilePosition = position;
			wPObject.projectilePosition.x += 50.f;

			if (wPObject.projectileSpawned == true) {
				std::cout << "True" << std::endl;
			}
			else if (wPObject.projectileSpawned == false) {
				std::cout << "false" << std::endl;
			}
		}
		/*if (IsKeyPressed(KEY_SPACE)) {
			health -= 10;
		}*/

		if (health == 0) {
			isWizardAlive = false;
			texture = LoadTexture("skull.png");
			texture.height = 25;
			texture.width = 25;
		}
	}
}

wizardProjectile::wizardProjectile()
{
	projectile = LoadTexture("crate.png");
	projectileSpawned = false;
}

wizardProjectile::~wizardProjectile()
{
	UnloadTexture(projectile);
}

void wizardProjectile::draw()
{
	DrawTextureEx(projectile, projectilePosition, 0.0f, 2.25f, WHITE);
}

void wizardProjectile::update(float deltaTime)
{
	projectilePosition.x++;
}
