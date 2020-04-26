#ifndef OBJ
#define OBJ

#include "FrameSDL.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include <string>
#include <Windows.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

//Window setting - should not be change!
const int hscale = 30;
const int wscale = 30;

const int SCREEN_WIDTH = hscale * wscale;
const int SCREEN_HEIGHT = hscale * wscale;
const std::string WINDOW_TITLE = "Simple Snake by Do Van Dat";
const std::string bgFile = "background.jpg";

//Speed: >= 50 && <= 80 (50 is the fastest speed - This should not be change because it can cause errors)
const int speed = 80;

class Game 
{
public:
	Game();
	~Game();

	struct snakeLocation {
		int x = 0;
		int y = 0;
		int prex = 0;
		int prey = 0;
	} snakeLoc;

	struct fruitLocation {
		int x = 0;
		int y = 0;
	} fruitLoc;


	//Tail positions
	std::vector <int> tailX;
	std::vector <int> tailY;
	

	//Rect of snake and fruit
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

	//Render Snake and Fruit

	void renderSnake(SDL_Renderer* renderer, int hscale);

	void renderFruit(SDL_Renderer* renderer);

	//Get fruit location and check collision

	void getFruitLoc(int hscale, int wscale);

	bool checkCollision();

	//Render in game

	void renderScore(SDL_Renderer* renderer, int hscale, int wscale);

	void renderGameOver(SDL_Renderer* renderer, int hscale, int wscale);

	void renderGameWin(SDL_Renderer* renderer, int hscale, int wscale);

	//Direction and move

	void moveDirection();

	void moveUp(float delta);

	void moveDown(float delta);
	
	void moveLeft(float delta);

	void moveRight(float delta);

	void updateMove(float delta);

	//Run Game

	void gameOver(SDL_Renderer* renderer);

	void gameLoop(SDL_Renderer* renderer, SDL_Texture* bgImage);

	void firstFruit(SDL_Renderer* renderer);
};

#endif
