#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "raylib.h"

namespace MyGame {
	namespace GameManager {
		extern int screenWidth;
		extern int screenHeight;

		enum ActualScene {
			Menu,
			Game,
			Gameover
		};

		extern ActualScene actualScene;

		void runGame();
	}
}
#endif // !GAME_H



