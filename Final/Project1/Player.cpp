#include "player.h"

namespace MyGame {
	namespace Player {

		Player ship;
		float playerRotation = 45.0f;
		void init() {
			ship.rec.width = 50;
			ship.rec.height = 50;
			ship.rec.x = (GetScreenWidth() / 2 - 550) - ship.rec.width  / 2;
			ship.rec.y = GetScreenHeight() / 2 - ship.rec.height / 2;
			ship.color = WHITE;
		}

		void update() {

			static float playerSpeed = 200.0f;
			
			ship.rec.y -= playerSpeed * GetFrameTime();

			if (IsKeyDown(KEY_SPACE))
			{
				playerSpeed = -200.0f;
			}
			if (IsKeyReleased(KEY_SPACE))
			{
				playerSpeed = 200.0f;
			}
			
		}

		void draw() {
			DrawRectanglePro(ship.rec, { 0,0 }, playerRotation, ship.color);
		}
	}
}