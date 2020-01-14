#include "player.h"

namespace MyGame {
namespace Player {

	Player avatar;
	
	void init() {

		avatar.rec.width = 30;
		avatar.rec.height = 30;
		avatar.rec.x = (GetScreenWidth() / 2) - avatar.rec.width  / 2;
		avatar.rec.y = GetScreenHeight() / 2 + 200 - avatar.rec.height / 2;
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
	}

	void draw() {

		DrawRectangleRec(avatar.rec, avatar.color);
	}
}
}