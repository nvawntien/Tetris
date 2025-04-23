#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>
#include <unordered_map>
#include <deque>
#include "constants.h"

class Utils {
    public:
        static Utils& getInstance();
        SDL_Window *getWindow();
        SDL_Renderer *getRenderer();
        void initSDL();
        void quitSDL();
        SDL_Texture *loadImage(const std :: string &path);
        SDL_Texture *loadText(const std :: string &text, SDL_Color color);
        SDL_Texture *loadStats(const std :: string &text, SDL_Color color);
    private:
        Utils() = default;
        ~Utils() = default;
        Utils(const Utils&) = delete;
        Utils& operator=(const Utils&) = delete;
        
        
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        TTF_Font *font = nullptr;
        TTF_Font *font1 = nullptr;
};

#endif