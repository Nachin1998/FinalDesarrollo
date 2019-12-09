#include "enemy.h"

#include <iostream>
#include <ctime>

namespace MyGame {
	namespace Enemy {

		Enemy obstacles[maxObst];

		static float obstacleSpeed = 200.0f;

		void init() {
			srand(time(0));
			obstacles[maxObst].rec.width = 50;
			obstacles[maxObst].rec.height = 50;
			obstacles[maxObst].rec.x = GetScreenWidth() - obstacles[maxObst].rec.width / 2;
			obstacles[maxObst].rec.y = rand() % GetScreenHeight();
			obstacles[maxObst].color = RED;
		}

		void update() {
			obstacles[maxObst].rec.x -= obstacleSpeed * GetFrameTime();

			if (obstacles[maxObst].rec.x + obstacles[maxObst].rec.width < 0)
			{
				obstacles[maxObst].rec.x = GetScreenWidth();
				obstacles[maxObst].rec.y = rand() % GetScreenHeight();
			}
		}

		void draw() {
			DrawRectangleRec(obstacles[maxObst].rec, obstacles[maxObst].color);
		}
	}
}