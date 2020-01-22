#include "game_manager.h"

#include "elements\element_manager\element_manager.h"
#include "level_manager\level_manager.h"
#include "entities\player\player.h"

#include "entities\enemy\enemy.h"

namespace MyGame {
namespace GameManager {

	static void init();
	static void update();
	static void draw();
	static void deInit();

	//Music bgMusic;

	ActualScene actualScene = Game;

	void runGame() {
		init();

		// Main game loop
		while (!WindowShouldClose())
		{
			update();
			draw();
		}
		//gameplay::deInit();
		deInit();
	}

	void init() {

		InitWindow(screenWidth, screenHeight, "I dont know yet");
		//InitAudioDevice();

		//bgMusic = LoadMusicStream("res/Music/pongSong.ogg");

		SetExitKey(KEY_F4);

		//menu::init();
		//gameplay::init();
		//gameOver::init();
		Player::init();
		ElementManager::init();
		LevelManager::init();

		//Enemy::init();
		
		//PlayMusicStream(bgMusic);
		//SetMusicVolume(bgMusic, 1.0f);

		//SetExitKey(KEY_F4);
	}

	void update() {

		//UpdateMusicStream(bgMusic);
		switch (actualScene) {
		case Menu:
			//menu::update(endGame);
			break;
		case Game:
			Player::update();
			ElementManager::update();
			LevelManager::update();

			//Enemy::update();
			//gameplay::update();
			break;

		case Gameover:
			//gameOver::update(endGame);
			break;

		default:
			break;
		}
	}

	void draw() {

		BeginDrawing();

		ClearBackground(BLACK);
		switch (actualScene) {
		case Menu:
			//menu::draw();
			break;
		case Game:
			Player::draw();
			ElementManager::draw();
			LevelManager::draw();

			//Enemy::draw();
			break;
		case Gameover:
			//gameOver::draw();
			break;
		default:
			DrawText("An error has occurred please contact a Dev", screenWidth / 2, screenHeight / 2, 20, RED);
			break;
		}
		EndDrawing();
	}

	void deInit() {

		//UnloadMusicStream(bgMusic);
		CloseAudioDevice();
		CloseWindow();
	}
}
}



