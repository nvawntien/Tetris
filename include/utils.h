#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL_mixer.h>  
#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <unordered_map>
#include <deque>
#include "constants.h"

class Utils {
    public:
        static Utils& getInstance();
        SDL_Window *getWindow();
        SDL_Renderer *getRenderer();
        Mix_Music* getMusic();
        void initSDL();
        void quitSDL();
        void loadHighScores(const std :: string& filename, std::vector <int>& highScores);
        void saveHighScores(const std :: string& filename, std::vector <int>& highScore);
        void updateHighScores(int newScore, std::vector<int>& highScores);
        SDL_Texture *loadImage(const std :: string &path);
        SDL_Texture *loadText(const std :: string &text, SDL_Color color);
        SDL_Texture *loadStats(const std :: string &text, SDL_Color color);
        Mix_Chunk* loadSoundEffect(const std::string& path);
        private:
        Utils() = default;
        ~Utils() = default;
        Utils(const Utils&) = delete;
        Utils& operator=(const Utils&) = delete;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        Mix_Music* backgroundMusic = nullptr;
        TTF_Font *font = nullptr;
        TTF_Font *font1 = nullptr;
};

#endif