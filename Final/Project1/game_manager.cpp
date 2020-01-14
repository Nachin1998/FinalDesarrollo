#include "game_manager.h"

#include "player.h"
#include "element_manager.h"

#include "enemy.h"

namespace MyGame {
namespace GameManager {
	static void init();
	static void update();
	static void draw();
	static void deInit();

	int screenWidth = 1500;
	int screenHeight = 800;

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

		//menu::init();
		//gameplay::init();
		//gameOver::init();
		Player::init();
		ElementManager::init();

		Enemy::init();
		
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

			Enemy::update();
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

			Enemy::draw();
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



