#include "air_element.h"

#include <iostream>

#include "elements\element_manager\element_manager.h"
#include "entities\player\player.h"

namespace MyGame {
namespace AirElement {
using namespace ElementManager;
using namespace Player;

	static void speedBoostUpdate();

	float timer = GetFrameTime();
	Vector2 mousePosition = GetMousePosition();

	struct Aim {
		Vector2 startingPoint;
		Vector2 aimingPoint;
		float thick;
		bool active;
		Color color;
	};

	Ability currentAbility = none;

	Aim aim;

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
			speedBoostUpdate();
			break;

		case third:
			break;

		default:
			std::cout << "There was an error in the air ability update selection." << std::endl;
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
			break;

		default:
			std::cout << "There was an error in the air ability drawing selection." << std::endl;
			break;
		}
	}

	void speedBoostUpdate() {


		float speedAux = avatar.movementSpeed;
		timer += GetFrameTime();

		if (timer < 3.0f)
		{
			avatar.movementSpeed += 300.0f * GetFrameTime();
		}
		
		if(timer>3.0f)
		{
			avatar.movementSpeed = 200.0f;
			timer = 0;
			currentAbility = none;
		}
	}



}
}