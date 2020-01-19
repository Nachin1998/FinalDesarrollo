#include "player.h"

#include <math.h>

namespace MyGame {
namespace Player {

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
		avatar.rec.x = (GetScreenWidth() / 2) + avatar.rec.width  / 2;
		avatar.rec.y = GetScreenHeight() / 2 + 200 + avatar.rec.height / 2;
		avatar.position.x = avatar.rec.x;
		avatar.position.y = avatar.rec.y;
		avatar.health = 100.0f;
		avatar.shield = 0.0f;
		avatar.powerActive = false;
		avatar.movementSpeed = 200.0f;
		avatar.color = WHITE;
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
			avatar.jump = true;
		}

		if (avatar.jump == true)
		{
			avatar.rec.y -= jumpForce * GetFrameTime();
		}

		if (avatar.rec.y < 580.0f)
		{
			jumpForce -= 500.0f * GetFrameTime();
		}

		/*if (avatar.rec.y >= 600.0f)
		{
			avatar.jump = false;
			jumpForce = 800.0f;
		}*/
	}
}
}