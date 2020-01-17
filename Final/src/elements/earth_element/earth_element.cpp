#include "earth_element.h"

#include <iostream>

#include "entities\player\player.h"
#include "elements\element_manager\element_manager.h"

namespace MyGame {
namespace EarthElement {
	using namespace ElementManager;
	using namespace Player;

	static void stoneShieldUpdate();
	static void stoneShieldDraw();

	float timer = GetFrameTime();

	void init() {
		timer = 0;
	}

	void update() {

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && currentAbility == none)
		{
			currentAbility = first;
		}

		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON) && currentAbility == none)
		{
			currentAbility = second;
		}

		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && currentAbility == none)
		{
			currentAbility = third;
		}

		switch (currentAbility)
		{
		case none:
			break;

		case first:
			break;

		case second:
			break;

		case third:
			stoneShieldUpdate();
			break;

		default:
			std::cout << "There was an error in the earth ability update selection." << std::endl;
			break;
		}

		/*if (currentAbility == first)
		{

		}*/
	}

	void draw() {

		switch (currentAbility)
		{
		case none:
			break;

		case first:
			break;

		case second:
			break;

		case third:
			stoneShieldDraw();
			break;

		default:
			std::cout << "There was an error in the earth ability drawing selection." << std::endl;
			break;
		}

		
	}

	void stoneShieldUpdate() {
		timer += GetFrameTime();

		if (timer < 5.0f)
		{
			avatar.shield += 100.0f;
		}

		if (timer > 5.0f)
		{
			avatar.shield = 0;
			timer = 0;
			currentAbility = none;
		}

	}

	void stoneShieldDraw() {
		timer += GetFrameTime();

		if (timer < 5.0f)
		{
			DrawRectangleLinesEx(avatar.rec, 3, WHITE);
		}
	}
}
}