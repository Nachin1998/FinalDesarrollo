#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

namespace MyGame {
namespace Player {

	struct Player {
		Rectangle rec;
		float health;
		float shield;
		float movementSpeed;
		float rotation;
		bool powerActive;
		bool onGround;
		bool onAir;
		bool jumping;
		bool alive;
		Color color;
	};

	struct Bar {
		Rectangle rec;
		Color color;
	};

	extern Player avatar;
	extern Bar healthBar;
	extern Bar manaBar;
	extern Color playerEdge;
	 
	void init();
	void update();
	void draw();
}
}

#endif
