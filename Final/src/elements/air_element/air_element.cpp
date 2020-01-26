#include "air_element.h"

#include <iostream>

#include "elements\element_manager\element_manager.h"
#include "entities\player\player.h"

namespace MyGame {
namespace AirElement {
using namespace ElementManager;
using namespace Player;

	static void speedBoostUpdate();
	static void areaPushInit();
	static void areaPushUpdate();
	static void areaPushDraw();

	float timer = GetFrameTime();
	Vector2 mousePosition = GetMousePosition();

	struct AirBubble {
		Vector2 position;
		float radius;
		bool active;
		Color color;
	};

	struct Aim {
		Vector2 startingPoint;
		Vector2 aimingPoint;
		float thick;
		bool active;
		Color color;
	};

	Ability currentAbility = none;

	Aim aim;
	AirBubble airBubble;

	void init() {
		areaPushInit();
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
			areaPushUpdate();
			break;

		default:
			std::cout << "There was an error in the air ability update selection." << std::endl;
			break;
		}
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
			areaPushDraw();
			break;

		default:
			std::cout << "There was an error in the air ability drawing selection." << std::endl;
			break;
		}
	}

	void areaPushInit() {

		airBubble.position.x = avatar.rec.x + avatar.rec.width / 2;
		airBubble.position.y = avatar.rec.y + avatar.rec.height / 2;
		airBubble.radius = 25.0f;
		airBubble.active = false;
		airBubble.color = SKYBLUE;
	}

	void speedBoostUpdate() {

		timer += GetFrameTime();

		if (timer < 3.0f)
		{
			avatar.movementSpeed += 250.0f * GetFrameTime();
		}
		
		if(timer > 3.0f)
		{
			avatar.movementSpeed = 500.0f;
			timer = 0;
			currentAbility = none;
		}
	}

	void areaPushUpdate() {

		float timer = 0;
		
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			airBubble.active = true;
		}
		else
		{
			airBubble.active = false;
			currentAbility = none;
		}
			
		if (airBubble.active)
		{
			airBubble.position.x = avatar.rec.x + avatar.rec.width / 2;
			airBubble.position.y = avatar.rec.y + avatar.rec.height / 2;
			airBubble.radius += 25.0F * GetFrameTime();
		}
		else
		{
			airBubble.radius = 5.0F;
		}
	}

	void areaPushDraw() {

		if (airBubble.active)
		{
			DrawCircleLines(airBubble.position.x, airBubble.position.y, airBubble.radius, airBubble.color);
		}
	}



}
}