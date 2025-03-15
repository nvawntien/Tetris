#ifndef UTILS_H
#define UTILS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const char* WINDOW_TITLE;

struct Util {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;

    void logSDLError(const std :: string &msg, bool fatal);
    void initSDL(SDL_Window** window, SDL_Renderer** renderer);
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    SDL_Texture *loadTexture(const std :: string &path, SDL_Renderer *renderer);
};

#endif