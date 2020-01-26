#include "fire_element.h"

#include <iostream>
#include <math.h>

#include "elements\element_manager\element_manager.h"
#include "entities\player\player.h"

namespace MyGame{
namespace FireElement {
using namespace ElementManager;
using namespace Player;

	static void fireballInit();
	static void fireballUpdate();
	static void fireballDraw();

	Vector2 mousePosition = GetMousePosition();

	struct Fireball {
		Vector2 position;
		float radius;
		Vector2 speed;
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

	Fireball fireball;
	Aim aim;

	void init() {
		
		fireballInit();
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
			fireballUpdate();
			break;

		case second:
			break;

		case third:
			break;

		default:
			std::cout << "There was an error in the fire ability update selection." << std::endl;
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
			fireballDraw();
			break;

		case second:
			break;

		case third:
			break;

		default:
			std::cout << "There was an error in the fire ability drawing selection." << std::endl;
			break;
		}
	}

	void fireballInit() {
		
		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
		aim.active = false;
		aim.thick = 2.0f;
		aim.aimingPoint = GetMousePosition();
		aim.color = GREEN;

		fireball.radius = 10.0f;
		fireball.speed = { 500.0f, 500.0f };
		fireball.active = false;
		fireball.color = YELLOW;

		fireball.position = aim.startingPoint;
	}
	
	void fireballUpdate() {

		Vector2 lookingDirection;
		float angle;

		aim.active = true;

		angle = atan2(GetMousePosition().y, GetMousePosition().x) * RAD2DEG - 90.0f;

		avatar.rotation = angle;

		if (aim.active)
		{
			aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;
			aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
			aim.aimingPoint = GetMousePosition();

			
		}

		if (fireball.active)
		{
			//fireball.position.x += fireball.speed.x * GetFrameTime();
			//fireball.position.y -= fireball.speed.y * GetFrameTime();

			fireball.position.x += fireball.speed.x * GetFrameTime() * 200.0f;
			fireball.position.y += fireball.speed.y * GetFrameTime() * 200.0f;
		}
		else
		{
			//fireball.position.x = aim.startingPoint.x;
			//fireball.position.y = aim.startingPoint.y;
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			fireball.active = true;
		}

		

		if (fireball.position.x < 0 || fireball.position.x > GetScreenWidth() ||
			fireball.position.y < 0 || fireball.position.y > GetScreenHeight())
		{
			fireball.active = false;
			aim.active = false;
			currentAbility = none;
		}
		
	}

	void fireballDraw() {

		if (aim.active)
		{
			DrawLineEx(aim.startingPoint, aim.aimingPoint, aim.thick, aim.color);
		}

		if (fireball.active)
		{
			DrawCircleV(fireball.position, fireball.radius, fireball.color);
		}
	}
}
}