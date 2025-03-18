#ifndef UTILS_H
#define UTILS_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <unordered_map>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int BLOCK_SIZE;
extern const int GRID_WIDTH;
extern const int GRID_HEIGHT;
extern const char* WINDOW_TITLE;

class Util {
    public:
        static Util& getInstance();
        SDL_Window *getWindow();
        SDL_Renderer *getRenderer();
        TTF_Font *getFont();
        void initSDL();
        void quitSDL();
        SDL_Texture *loadImage(const std :: string &path);
        SDL_Texture *loadText(const std :: string &text, SDL_Color color);
    private:
        Util() = default;
        ~Util() = default;
        Util(const Util&) = delete;
        Util& operator=(const Util&) = delete;
        
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        TTF_Font *font = nullptr;
};

#endif