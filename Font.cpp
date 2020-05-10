#include "Font.h"

font::font() {};
font::~font() {
    SDL_DestroyTexture(printScore);
    printScore = NULL;
    SDL_DestroyTexture(printGameOver1);
    printGameOver1 = NULL;
    SDL_DestroyTexture(printGameOver2);
    printGameOver2 = NULL;
};

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


void font::renderScore(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 80, 120, 140, 200);
    SDL_RenderFillRect(renderer, &scoreRect);
    SDL_RenderCopy(renderer, printScore, NULL, &scoreRect);
}

void font::renderOver(const std::string& message1, const std::string& message2, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, SDL_Texture* background) {
    printGameOver1 = renderText(message1, fontFile, color, fontSize, renderer);
    printGameOver2 = renderText(message2, fontFile, color, fontSize, renderer);

    SDL_RenderCopy(renderer, background, NULL, NULL);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderDrawRect(renderer, &gameoverRect1);
    SDL_RenderDrawRect(renderer, &gameoverRect2);

    SDL_RenderCopy(renderer, printGameOver1, NULL, &gameoverRect1);
    SDL_RenderCopy(renderer, printGameOver2, NULL, &gameoverRect2);

    SDL_RenderPresent(renderer);
}

void font::renderMenu(const std::string& message1, const std::string& message2, const std::string& fontFile, SDL_Color color, int fontSize, SDL_Renderer* renderer, SDL_Texture* background) {
    printMenu1 = renderText(message1, fontFile, color, fontSize, renderer);
    printMenu2 = renderText(message2, fontFile, color, fontSize, renderer);

    SDL_RenderCopy(renderer, background, NULL, NULL);
    
    SDL_SetRenderDrawColor(renderer, 230, 255, 130, 0);
    SDL_RenderDrawRect(renderer, &menuRect1);
    SDL_RenderDrawRect(renderer, &menuRect2);
    
    SDL_RenderCopy(renderer, printMenu1, NULL, &menuRect1);
    SDL_RenderCopy(renderer, printMenu2, NULL, &menuRect2);

    SDL_RenderPresent(renderer);
}