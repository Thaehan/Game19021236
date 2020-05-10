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
	SDL_Color mColor = { 220, 255, 130, 210 };
	SDL_Color sColor = { 180, 230, 110, 210 };
	SDL_Color gColor = { 210, 110, 110, 210 };

	SDL_Rect menuRect1 = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4 };
	SDL_Rect menuRect2 = { SCREEN_WIDTH / 8, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 4 * 3, SCREEN_HEIGHT / 4 };
	SDL_Rect scoreRect = { edge, edge, SCREEN_WIDTH / 3, topbar - edge };
	SDL_Rect gameoverRect1 = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 4 };
	SDL_Rect gameoverRect2 = { SCREEN_WIDTH / 20, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 20 * 18, SCREEN_HEIGHT / 4 };

	SDL_Texture* printMenu1 = NULL;
	SDL_Texture* printMenu2 = NULL;
	SDL_Texture* printScore = NULL;
	SDL_Texture* printGameOver1 = NULL;
	SDL_Texture* printGameOver2 = NULL;

	SDL_Texture* renderText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer);

	void renderScore(SDL_Renderer* renderer);

	void renderOver(const std::string& message1, const std::string& message2, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, SDL_Texture* background);

	void renderMenu(const std::string& message1, const std::string& message2, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, SDL_Texture* background);

};

#endif
