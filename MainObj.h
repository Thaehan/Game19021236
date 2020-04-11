#ifndef OBJ
#define OBJ

#include "FrameSDL.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <Windows.h>

//Window setting
const int hscale = 24;
const int wscale = 24;

const int SCREEN_WIDTH = hscale * wscale;
const int SCREEN_HEIGHT = hscale * wscale + 1;
const std::string WINDOW_TITLE = "Simple snake by Thaehan";

//Speed: >= 50 (50 is the fastest speed)
const int speed = 80;

class Game 
{
public:
	Game();
	~Game();

	struct snakeLocation {
		int x;
		int y;
		int prex = 0;
		int prey = 0;
	} snakeLoc;

	struct fruitLocation {
		int x;
		int y;
	} fruitLoc;


	SDL_Rect snakeBox = { 0, 0, 0, 0 };
	SDL_Rect fruitBox = { 0, 0, hscale, wscale };

	float Stime = SDL_GetTicks() / speed;

	int tailLength = 0;

	SDL_Event event;

	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;

	bool checkMove = false;
	bool redo = false;

	void renderSnake(SDL_Renderer* renderer, int hscale, std::vector <int>& tailX, std::vector <int>& tailY);

	void renderFruit(SDL_Renderer* renderer);

	void getFruitLoc(int hscale, int wscale, std::vector <int> &tailX, std::vector <int> &tailY);

	bool checkCollision();

	void printScore(SDL_Renderer* renderer, int hscale, int wscale);

	void gameOver(SDL_Renderer* renderer, int hscale, int wscale);

	void gameWin(SDL_Renderer* renderer, int hscale, int wscale);

	void moveDirection();

	void gameLoop(SDL_Renderer* renderer, std::vector <int>& tailX, std::vector <int>& tailY);
};

#endif
