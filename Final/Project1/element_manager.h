#ifndef ELEMENT_MANAGER_H
#define ELEMENT_MANAGER_H

#include "raylib.h"

namespace MyGame {
namespace ElementManager {
	
	enum ElementSelection {
		Water,
		Earth,
		Fire,
		Air
	};

	enum Ability {
		none,
		first,
		second,
		third
	};

	extern ElementSelection actualElement;
	extern Ability currentAbility;
	extern Vector2 mousePosition;

	void init();
	void update();
	void draw();
}
}

#endif