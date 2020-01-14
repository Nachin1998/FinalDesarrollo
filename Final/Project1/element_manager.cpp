#include "element_manager.h"

#include "player.h"
#include "fire_element.h"

#include "raylib.h"

namespace MyGame {
namespace ElementManager {
using namespace Fire;
using namespace Player;
	
	static void actualElementUpdate();

	ElementSelection actualElement = Air;

	void init() {
		Fire::init();
	}

	void update() {
		
		if (IsKeyPressed(KEY_ONE))
		{
			avatar.color = BLUE;
			actualElement = Water;
		}

		if (IsKeyPressed(KEY_TWO))
		{
			avatar.color = BROWN;
			actualElement = Earth;
		}

		if (IsKeyPressed(KEY_THREE))
		{
			avatar.color = RED;
			actualElement = Fire;
		}

		if (IsKeyPressed(KEY_FOUR))
		{
			avatar.color = RAYWHITE;
			actualElement = Air;
		}

		actualElementUpdate();
	}

	void draw() {
		if (actualElement == Fire) {
			Fire::draw();
		}
	}

	void actualElementUpdate() {
		if (actualElement == Fire) {
			Fire::update();
		}
	}
}
}