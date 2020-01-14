#include "player.h"

namespace MyGame {
	namespace Player {

		Player avatar;

		struct Aim {
			Vector2 startingPoint;
			Vector2 aimingPoint;
			float thick;
			bool active;
			Color color;
		};

		Aim aim;
		
		void init() {
			avatar.rec.width = 30;
			avatar.rec.height = 30;
			avatar.rec.x = (GetScreenWidth() / 2) - avatar.rec.width  / 2;
			avatar.rec.y = GetScreenHeight() / 2 + 200 - avatar.rec.height / 2;
			avatar.movementSpeed = 200.0f;
			avatar.color = WHITE;

			aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
			aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
			aim.active = false;
			aim.thick = 2.0f;
			aim.aimingPoint = GetMousePosition();
			aim.color = RED;
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

			if (IsKeyPressed(KEY_SPACE))
			{
				aim.active = true;
			}

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				aim.active = false;
			}

			aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
			aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;

			aim.aimingPoint = GetMousePosition();
		}

		void draw() {
			DrawRectangleRec(avatar.rec, avatar.color);

			if (aim.active) 
			{
				DrawLineEx(aim.startingPoint, aim.aimingPoint, aim.thick, aim.color);
			}
		}
	}
}