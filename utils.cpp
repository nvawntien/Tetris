#include "utils.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BLOCK_SIZE = 25;
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 20;
const char* WINDOW_TITLE = "TETRIS GAME";

Util& Util :: getInstance() {
    static Util instance;
    return instance;
}

SDL_Window* Util :: getWindow() {
    return window;
}

SDL_Renderer* Util :: getRenderer() {
    return renderer;
}

TTF_Font* Util :: getFont() {
    return font;
}

void Util :: initSDL() {
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("font/MuseoSans500.otf", 30);
}

void Util :: quitSDL() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

SDL_Texture* Util::loadImage(const std :: string &path) {
    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);   
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

SDL_Texture* Util::loadText(const std::string& text, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
    SDL_FreeSurface(surface);
    return texture;
}

