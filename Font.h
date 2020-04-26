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
	SDL_Rect scoreRect;
	SDL_Rect gameoverRect;

	SDL_Texture* printScore = NULL;
	SDL_Texture* printGameOver = NULL;

	SDL_Texture* renderText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer);

	void renderScore(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, int tailLength);

	void renderGameOver(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, int tailLength);

};

#endif
