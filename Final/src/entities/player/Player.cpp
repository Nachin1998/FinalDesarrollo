#include "player.h"

#include "level_manager\level_manager.h"

#include <math.h>

namespace MyGame {
namespace Player {
using namespace LevelManager;

	static void movement();
	static void jump();

	Player avatar;
	Vector2 rotationDirection;
	Vector2 mousePosition = GetMousePosition();
	static float rotationAngle = 0.0f;
	static float jumpForce = 500.0f;
	
	void init() {

		avatar.rec.width = 30;
		avatar.rec.height = 30;
		avatar.rec.x = GetScreenWidth() / 2 - avatar.rec.width  / 2;
		avatar.rec.y = (GetScreenHeight() / 2 + 200) - avatar.rec.height / 2;
		avatar.health = 100.0f;
		avatar.shield = 0.0f;
		avatar.onGround = true;
		avatar.jumping = false;
		avatar.powerActive = false;
		avatar.movementSpeed = 200.0f;
		avatar.color = GREEN;
	}

	void update() {

		/*if (avatar.rec.y / 2 - avatar.rec.height / 2 <= platforms[0].rec.y / 2 - platforms[0].rec.height / 2)
		{
			avatar.rec.y += 0.1;
		}*/
		
		movement();
		jump();

		/*rotationDirection.x = GetMousePosition().x - avatar.rec.x;
		rotationDirection.y = GetMousePosition().y - avatar.rec.y;

		rotationAngle = atan2(rotationDirection.y, rotationDirection.x) + GetMousePosition().x;

		avatar.rotation = rotationAngle;*/
	}

	void draw() {

		DrawRectangleRec(avatar.rec, avatar.color);
		//DrawRectanglePro(avatar.rec, {0,0}, avatar.rotation, avatar.color);
	}

	void movement() {
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
		{
			avatar.rec.x += avatar.movementSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
		{
			avatar.rec.x -= avatar.movementSpeed * GetFrameTime();
		}
	}

	void jump() {

		if (IsKeyPressed(KEY_SPACE))
		{
			avatar.jumping = true;
		}

		if (avatar.jumping)
		{
			avatar.rec.y -= jumpForce * GetFrameTime();

			if (avatar.rec.y < 780.0f)
			{
				jumpForce -= 500.0f * GetFrameTime();
			}
		}

		for (int i = 0; i < maxPlatforms; i++)
		{
			if (CheckCollisionRecs(avatar.rec, platforms[i].rec))
			{
				avatar.jumping = false;
				jumpForce = 500.0f;
			}
		}
	}
		
		
		/*if (avatar.rec.y >= 600.0f)
		{
			avatar.jump = false;
			jumpForce = 800.0f;
		}*/
}
}
