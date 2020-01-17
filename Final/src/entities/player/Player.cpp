#include "player.h"

#include <math.h>

namespace MyGame {
namespace Player {

	Player avatar;
	Vector2 rotationDirection;
	Vector2 mousePosition = GetMousePosition();
	static float rotationAngle = 0.0f;
	
	void init() {

		avatar.rec.width = 30;
		avatar.rec.height = 30;
		avatar.rec.x = (GetScreenWidth() / 2) - avatar.rec.width  / 2;
		avatar.rec.y = GetScreenHeight() / 2 + 200 - avatar.rec.height / 2;
		avatar.health = 100.0f;
		avatar.shield = 0.0f;
		avatar.powerActive = false;
		avatar.movementSpeed = 200.0f;
		avatar.color = WHITE;
	}

	void update() {

		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
		{
			avatar.rec.x += avatar.movementSpeed * GetFrameTime();
		}
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
		{
			avatar.rec.x -= avatar.movementSpeed * GetFrameTime();
		}

		rotationDirection.x = mousePosition.x - avatar.rec.x;
		rotationDirection.y = mousePosition.y - avatar.rec.y;

		rotationAngle = atan2(rotationDirection.y, rotationDirection.x) + GetMousePosition().x;

		avatar.rotation = rotationAngle;
	}

	void draw() {

		DrawRectangleRec(avatar.rec, avatar.color);
	}
}
}