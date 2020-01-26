#include "player.h"

#include "level_manager\level_manager.h"

#include <iostream>
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
	static float jumpForce = 800.0f;
	static float gravity = 90.0f;
	
	void init() {

		avatar.rec.width = 30;
		avatar.rec.height = 30;
		avatar.rec.x = GetScreenWidth() / 2 - avatar.rec.width  / 2;
		avatar.rec.y = (GetScreenHeight() / 2 + 200) - avatar.rec.height / 2;
		avatar.health = 100.0f;
		avatar.shield = 0.0f;
		avatar.onGround = true;
		avatar.onAir = false;
		avatar.jumping = false;
		avatar.powerActive = false;
		avatar.movementSpeed = 500.0f;
		avatar.color = GREEN;
	}

	void update() {

		movement();
		jump();

		/*rotationDirection.x = GetMousePosition().x - avatar.rec.x;
		rotationDirection.y = GetMousePosition().y - avatar.rec.y;

		rotationAngle = atan2(rotationDirection.y, rotationDirection.x) + GetMousePosition().x;

		avatar.rotation = rotationAngle;*/
	}

	void draw() {

		DrawRectangleRec(avatar.rec, avatar.color);
	}

	void movement() {
		int mapLimit = 1;

		if (avatar.rec.x + avatar.rec.width < GetScreenWidth() - mapLimit) 
		{
			if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
			{
				avatar.rec.x += avatar.movementSpeed * GetFrameTime();
			}
		}

		if (avatar.rec.x > mapLimit)
		{
			if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
			{
				avatar.rec.x -= avatar.movementSpeed * GetFrameTime();
			}
		}
		

		for (int i = 0; i < maxPlatforms; i++)
		{
			if (CheckCollisionRecs(avatar.rec, platforms[i].rec))
			{
				if ((avatar.rec.x + avatar.rec.width > platforms[i].rec.x + 1 &&
					avatar.rec.x + avatar.rec.width < platforms[i].rec.x + platforms[i].rec.width + avatar.rec.width - 1) &&
					avatar.rec.y + avatar.rec.height + 9.7 < platforms[i].rec.y + platforms[i].rec.height)
				{
					gravity = 0;
					avatar.jumping = false;
				}
				else
				{
					gravity = 90.0f;
				}
			}
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

			if (avatar.rec.y < 1500.0f)
			{
				jumpForce -= 1500.0f * GetFrameTime();
			}
		}

		for (int i = 0; i < maxPlatforms; i++)
		{
			if (!CheckCollisionRecs(avatar.rec, platforms[i].rec))
			{
				avatar.rec.y += gravity * GetFrameTime();
			}
			else
			{
				jumpForce = 800.0f;
			}
		}
	}
}
}
