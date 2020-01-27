#ifndef EARTH_ELEMENT
#define EARTH_ELEMENT

#include "raylib.h"

namespace MyGame {
namespace EarthElement {
	
	struct Shield {
		Rectangle rec;
		Color color;
	};

	void init();
	void update();
	void draw();

	extern Shield shield;
}
}

#endif
