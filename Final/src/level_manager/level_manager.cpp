#include "level_manager.h"

#include "entities\player\player.h"

namespace MyGame{
namespace LevelManager {
using namespace Player;
	Platform platforms[maxPlatforms];

	void init() {

		for (int i = 0; i < maxPlatforms; i++)
		{
			platforms[i].rec.width = 250.0f;
			platforms[i].rec.height = 10.0f;
			platforms[i].color = WHITE;
		}

		platforms[0].rec.width = GetScreenWidth();
		platforms[0].rec.height = 50.0f;
		platforms[0].rec.x = GetScreenWidth() / 2 - platforms[0].rec.width / 2;
		platforms[0].rec.y = GetScreenHeight() - 100;
	
		platforms[1].rec.x = GetScreenWidth() / 2 - platforms[1].rec.width / 2;
		platforms[1].rec.y = GetScreenHeight() / 2 - platforms[1].rec.height / 2;

		platforms[2].rec.x = GetScreenWidth() / 2 - 500 - platforms[3].rec.width / 2;
		platforms[2].rec.y = (GetScreenHeight() / 2 - 120) - platforms[3].rec.height / 2;
		
		platforms[3].rec.x = GetScreenWidth() / 2 - 500 - platforms[2].rec.width / 2;
		platforms[3].rec.y = (GetScreenHeight() / 2 + 120) - platforms[2].rec.height / 2;

		platforms[4].rec.x = GetScreenWidth() / 2 + 500 - platforms[4].rec.width / 2;
		platforms[4].rec.y = (GetScreenHeight() / 2 + 120) - platforms[4].rec.height / 2;

		platforms[5].rec.x = GetScreenWidth() / 2 + 500 - platforms[5].rec.width / 2;
		platforms[5].rec.y = (GetScreenHeight() / 2 - 120) - platforms[5].rec.height / 2;
	}

	void update() {

		for (int i = 0; i < maxPlatforms; i++)
		{
			if (CheckCollisionRecs(avatar.rec, platforms[i].rec))
			{
				platforms[i].color = RED;
			}
			else
			{
				platforms[i].color = WHITE;
			}
		}
		
	}

	void draw() {

		for (int i = 0; i < maxPlatforms; i++)
		{
			DrawRectangleRec(platforms[i].rec, platforms[i].color);
		}
	}
}
}