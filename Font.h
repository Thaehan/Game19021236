#ifndef FONT_H
#define FONT_H

#include "FrameSDL.h"
#include "snake.h"
#include "game.h"
#include "Fruit.h"
#include <SDL_ttf.h>
#include <SDL.h>

class font {
public:
	font();
	~font();
	SDL_Color sColor = { 180, 230, 110, 210 };
	SDL_Color gColor = { 210, 110, 110, 210 };

	SDL_Rect scoreRect = { edge, edge, SCREEN_WIDTH / 3, topbar - edge };
	SDL_Rect gameoverRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2 };

	SDL_Texture* printScore = NULL;
	SDL_Texture* printGameOver = NULL;

	SDL_Texture* renderText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer);

	void renderScore(SDL_Renderer* renderer);

	void renderOver(SDL_Renderer* renderer);

};

#endif
