#include "water_element.h"

#include <iostream>

#include "entities\player\player.h"

#include "elements\element_manager\element_manager.h"

namespace MyGame{
namespace WaterElement {
using namespace ElementManager;
using namespace Player;

	static void waterHealingUpdate();
	static void waterHealingDraw();

	void init() {

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
			waterHealingUpdate();
			break;

		default:
			std::cout << "There was an error in the water ability update selection." << std::endl;
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
			waterHealingDraw();
			break;

		default:
			std::cout << "There was an error in the water ability drawing selection." << std::endl;
			break;
		}
	}

	void waterHealingUpdate() {
		static float healthUp = 2.5f;
		static float waitTime = 10.0f;
		static float auxWaitTime = 1.0f;

		static float timer = 0.0f;
		static float auxTimer = 0.0f;

		timer += GetFrameTime();
		auxTimer += GetFrameTime();

		if (avatar.health + healthUp >= 300.0f)
		{
			healthUp = 300.0f - avatar.health;
		}
		else
		{
			healthUp = 10.0f;
		}

		if (timer <= waitTime)
		{
			if (auxTimer >= auxWaitTime)
			{
				avatar.health += healthUp;
				std::cout << avatar.health << std::endl;
				auxTimer = 0;
			}
		}

		if (timer > waitTime)
		{
			timer = 0;
			auxTimer = 0;
			currentAbility = none;
		}
	}

	void waterHealingDraw() {
		static float timer = 0;
		timer += GetFrameTime();

		if (timer <= 10.0f)
		{
			DrawRectangleLinesEx(avatar.rec, 3, GREEN);
		}
		else 
		{
			timer = 0;
		}
	}
}
}