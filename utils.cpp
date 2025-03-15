#include "utils.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "TETRIS GAME";

void Util :: logSDLError(const std:: string& msg, bool fatal) {
    std :: cerr << msg << " Error: " << SDL_GetError();
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void Util :: initSDL(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        logSDLError("SDL Init", true);
    }

    *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == nullptr) logSDLError("Create Window", true);
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer = nullptr) logSDLError("Create Renderer", true);
}

void Util :: quitSDL(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

SDL_Texture* Util::loadTexture(const std :: string &path, SDL_Renderer* renderer) {
    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);   
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}