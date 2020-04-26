#include "snake.h"
#include "FrameSDL.h"

snake::snake() {};
snake::~snake() {};

void snake::renderSnake(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// Gets x and y of all tail blocks and renders
	for (int i = 0; i < tailLength; i++) {
		snakeBox.x = tailX[i];
		snakeBox.y = tailY[i];
		SDL_RenderFillRect(renderer, &snakeBox);
	}

	snakeBox.x = x;
	snakeBox.y = y;

	SDL_RenderFillRect(renderer, &snakeBox);
}