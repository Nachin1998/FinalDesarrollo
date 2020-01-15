#include "fire_element.h"

#include "player.h"

namespace MyGame{
namespace Fire {
	using namespace Player;

	static void fireballInit();
	static void fireballUpdate();
	static void fireballDraw();

	struct Fireball {
		Vector2 position;
		float radius;
		float speed;
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

	Fireball fireball;
	Aim aim;

	void init() {
		
		fireballInit();
	}

	void update() {
		
		fireballUpdate();
	}

	void draw() {
		
		fireballDraw();
	}

	void fireballInit() {
		
		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;
		aim.active = false;
		aim.thick = 2.0f;
		aim.aimingPoint = GetMousePosition();
		aim.color = RED;

		
		fireball.radius = 15.0f;
		fireball.active = false;
		fireball.color = YELLOW;
	}
	
	void fireballUpdate() {
		Vector2 positionAux;

		fireball.position = aim.startingPoint;
		if (IsKeyPressed(KEY_SPACE))
		{
			aim.active = true;
		}

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			positionAux = aim.aimingPoint;
			aim.active = false;
			fireball.active = true;
		}

		aim.startingPoint.x = avatar.rec.x + avatar.rec.width / 2;;
		aim.startingPoint.y = avatar.rec.y + avatar.rec.height / 2;

		aim.aimingPoint = GetMousePosition();

		if (fireball.active) {
			if (fireball.position.x < positionAux.x) {
				fireball.position.x++;
			}
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