#include "element_manager.h"

#include "player.h"
#include "fire_element.h"
#include "air_element.h"
#include "earth_element.h"
#include "water_element.h"

#include <iostream>

#include "raylib.h"

namespace MyGame {
namespace ElementManager {
using namespace Player;
	
	static void actualElementUpdate();

	ElementSelection actualElement = Air;
	Ability currentAbility = none;

	void init() {
		FireElement::init();
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
			WaterElement::update();
			break;

		case Earth:
			EarthElement::update();
			break;

		case Fire:
			FireElement::update();
			break;

		case Air:
			AirElement::update();
			break;

		default:
			std::cout << "There was an error in the element manager update selection." << std::endl;
			break;
		}
	}

	void draw() {
		switch (actualElement)
		{
		case Water:
			WaterElement::draw();
			break;

		case Earth:
			EarthElement::draw();
			break;

		case Fire:
			FireElement::draw();
			break;

		case Air:
			AirElement::draw();
			break;

		default:
			std::cout << "There was an error in the element manager draw selection." << std::endl;
			break;
		}
	}
}
}