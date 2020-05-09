#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "Fruit.h"
#include "Font.h"
#include "background.h"
#include "FrameSDL.h"

class game {
public:
	game();
	~game();

	//Background
	SDL_Texture* bgImage = NULL;

	void gameLoop(SDL_Renderer* renderer);

private:

	void control();
	void move();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	
	void reset();

	void renderGameOver(SDL_Renderer* renderer);
	void renderGameWin(SDL_Renderer* renderer);

	//Event keyboard
	SDL_Event e;

	int score = 0;

	int stepx = 0;
	int stepy = 0;
};



#endif