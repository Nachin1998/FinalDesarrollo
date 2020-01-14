#include "fire_element.h"

#include "player.h"

namespace MyGame{
namespace Fire {
	using namespace Player;

	Aim aim;

	void init() {

		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
		aim.active = false;
		aim.thick = 2.0f;
		aim.aimingPoint = GetMousePosition();
		aim.color = RED;
	}

	void update() {

		if (IsKeyPressed(KEY_SPACE))
		{
			aim.active = true;
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			aim.active = false;
		}

		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;

		aim.aimingPoint = GetMousePosition();
	}

	void draw() {
		
		if (aim.active)
		{
			DrawLineEx(aim.startingPoint, aim.aimingPoint, aim.thick, aim.color);
		}
	}
}
}