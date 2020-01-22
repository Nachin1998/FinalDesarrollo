#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "raylib.h"

namespace MyGame {
	namespace LevelManager {
		
		const float gravity = 100.0f;
		const int maxPlatforms = 6;

		struct Platform {
			Rectangle rec;
			Color color;
		};

		extern Platform platforms[maxPlatforms];

		void init();
		void update();
		void draw();
	}
}

#endif