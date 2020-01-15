#include "fire_element.h"

#include <iostream>
#include <cmath>

#include "element_manager.h"
#include "player.h"

namespace MyGame{
namespace Fire {
using namespace ElementManager;
using namespace Player;

	static void fireballInit();
	static void fireballUpdate();
	static void fireballDraw();

	
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
			std::cout << "There was an error in the ability selection." << std::endl;
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
			std::cout << "There was an error in the ability drawing." << std::endl;
			break;
		}

		/*if (currentAbility == first) 
		{
			
		}*/
	}

	void fireballInit() {
		
		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
		aim.active = false;
		aim.thick = 2.0f;
		aim.aimingPoint = GetMousePosition();
		aim.color = RED;

		fireball.radius = 10.0f;
		fireball.speed = { 200.0f, 200.0f };
		fireball.active = false;
		fireball.color = YELLOW;

		fireball.position = aim.startingPoint;
	}
	
	void fireballUpdate() {

		aim.active = true;
		
		if (!fireball.active)
		{
			fireball.position = aim.startingPoint;
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			fireball.active = true;
		}

		/*if (fireball.active)
		{
			aim.active = false;
		}*/

		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
		aim.aimingPoint = GetMousePosition();

		if (fireball.active) 
		{
			if (fireball.position.x < aim.aimingPoint.x)
			{
				fireball.position.x += fireball.speed.x * GetFrameTime();
			}

			if (fireball.position.x >  aim.aimingPoint.x)
			{
				fireball.position.x-= fireball.speed.x * GetFrameTime();
			}

			if (fireball.position.y <  aim.aimingPoint.y)
			{
				fireball.position.y+= fireball.speed.y * GetFrameTime();
			}

			if (fireball.position.y > aim.aimingPoint.y)
			{
				fireball.position.y-= fireball.speed.y * GetFrameTime();
			}

			/*if (fireball.position.x < positionAuxX)
			{
				fireball.position.x += fireball.speed * GetFrameTime();
			}*/
		}

		if (fireball.position.x < 0 || fireball.position.x > GetScreenWidth() ||
			fireball.position.y < 0 || fireball.position.y > GetScreenHeight() ||
			(fireball.position.x == aim.aimingPoint.x))
		{
			fireball.active = false;
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