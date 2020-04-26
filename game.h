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

	bool redo = true;

	void gameLoop(SDL_Renderer* renderer, SDL_Texture* bgImage);

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

	SDL_Event e;

	int stepx = 0;
	int stepy = 0;
};



#endif