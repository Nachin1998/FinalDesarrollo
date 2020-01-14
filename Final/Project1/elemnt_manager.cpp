#include "element_manager.h"

#include "player.h"

#include "raylib.h"

namespace MyGame {
namespace ElementManager {
using namespace Player;

	static void actualElementUpdate();

	ElementSelection actualElement = Air;

	void init() {

	}

	void update() {
		if (IsKeyPressed(KEY_ONE)) 
		{
			avatar.color = BLUE;
			actualElement = Water;
		}
	}

	void draw() {
	
	}

	void actualElementUpdate() {

	}
}
}