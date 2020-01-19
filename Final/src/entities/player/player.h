#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace MyGame {
namespace Player {

	struct Player {
		Rectangle rec;
		float health;
		Vector2 position;
		float shield;
		float movementSpeed;
		float rotation;
		bool powerActive;
		bool jump;
		bool alive;
		Color color;
	};

	extern Player avatar;

	void init();
	void update();
	void draw();
}
}

#endif
