#include "Font.h"

font::font() {};
font::~font() {};

SDL_Texture* font::renderText(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer){
    //Open the font
    TTF_Font* font = TTF_OpenFont(fontFile.c_str(), fontSize);

    if (font == NULL) {
        std::cout << "TTF_OpenFont";
        return NULL;
    }

    //render to a surface as that's what TTF_RenderText returns
    SDL_Surface* surf = TTF_RenderText_Solid(font, message.c_str(), color);

    if (surf == NULL) {
        TTF_CloseFont(font);
        std::cout << "TTF_RenderText";
        return NULL;
    }

    //then load that surface into a texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == NULL) {
        std::cout << "CreateTexture";
    }

    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

void font::renderScore(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, int tailLength) {
    printScore = renderText(message, fontFile, color, fontSize, renderer);
    gameoverRect.x = SCREEN_WIDTH / 2;
    gameoverRect.y = 0;
    SDL_RenderCopy(renderer, printScore, &gameoverRect, NULL);
}


void font::renderGameOver(const std::string& message, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, int tailLength) {
    printGameOver = renderText(message, fontFile, color, fontSize, renderer);
    gameoverRect.x = SCREEN_WIDTH / 2;
    gameoverRect.y = SCREEN_HEIGHT / 2;
    SDL_RenderCopy(renderer, printScore, &gameoverRect, NULL);
}
