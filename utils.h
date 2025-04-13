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


constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr int BLOCK_SIZE = 25;
constexpr int CELL_WIDTH = 10;
constexpr int CELL_HEIGHT = 20;
constexpr int GRID_WIDTH = 272;
constexpr int GRID_HEIGHT = 534;
constexpr const char* WINDOW_TITLE = "TETRIS GAME";

class Utils {
    public:
        static Utils& getInstance();
        SDL_Window *getWindow();
        SDL_Renderer *getRenderer();
        TTF_Font *getFont();
        void initSDL();
        void quitSDL();
        SDL_Texture *loadImage(const std :: string &path);
        SDL_Texture *loadText(const std :: string &text, SDL_Color color);

    private:
        Utils() = default;
        ~Utils() = default;
        Utils(const Utils&) = delete;
        Utils& operator=(const Utils&) = delete;
        
        
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        TTF_Font *font = nullptr;
};

#endif