#ifndef FIRE_ELEMENT_H
#define FIRE_ELEMENT_H

#include "raylib.h"

namespace MyGame{
namespace Fire {

	struct Aim {
		Vector2 startingPoint;
		Vector2 aimingPoint;
		float thick;
		bool active;
		Color color;
	};
	extern Aim aim;

	void init();
	void update();
	void draw();
}
}

#endif
