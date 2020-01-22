#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "raylib.h"

namespace MyGame {
namespace GameManager {

	const int screenWidth = 1500;
	const int screenHeight = 800;

	enum ActualScene {
		Menu,
		Game,
		Gameover
	};

	extern ActualScene actualScene;

	void runGame();
}
}
#endif