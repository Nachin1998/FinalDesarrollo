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

	void gravity(Rectangle &rec, float gravity) {

		for (int i = 0; i < maxPlatforms; i++)
		{
			if (CheckCollisionRecs(rec, platforms[i].rec))
			{
				if ((rec.x + rec.width > platforms[i].rec.x + 1 &&
					rec.x + rec.width < platforms[i].rec.x + platforms[i].rec.width + rec.width - 1) &&
					rec.y + rec.height < platforms[i].rec.y + platforms[i].rec.height)
				{
					//jumpForce = 800.0f;
					gravity = 0;
					avatar.jumping = false;
				}
				else
				{
					gravity = 90.0f;
				}
			}
		}
		
	}
}
}