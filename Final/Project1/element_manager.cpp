#include "element_manager.h"

#include "player.h"
#include "fire_element.h"
#include "air_element.h"

#include "raylib.h"

namespace MyGame {
namespace ElementManager {
using namespace Fire;
using namespace Air;
using namespace Player;
	
	static void actualElementUpdate();

	ElementSelection actualElement = Air;
	Ability currentAbility = none;

	void init() {
		Fire::init();
	}

	void update() {
		
		if (IsKeyPressed(KEY_ONE))
		{
			currentAbility = none;
			avatar.color = BLUE;
			actualElement = Water;
		}

		if (IsKeyPressed(KEY_TWO))
		{
			currentAbility = none;
			avatar.color = BROWN;
			actualElement = Earth;
		}

		if (IsKeyPressed(KEY_THREE))
		{
			currentAbility = none;
			avatar.color = RED;
			actualElement = Fire;
		}

		if (IsKeyPressed(KEY_FOUR))
		{
			currentAbility = none;
			avatar.color = RAYWHITE;
			actualElement = Air;
		}

		actualElementUpdate();
	}

	void actualElementUpdate() {
		switch (actualElement)
		{
		case Water:
			break;
		case Earth:
			break;
		case Fire:
			Fire::update();
			break;
		case Air:
			Air::update();
			break;
		default:
			break;
		}
	}

	void draw() {
		if (actualElement == Fire) {
			Fire::draw();
		}
	}
}
}