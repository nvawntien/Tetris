#include "utils.h"

Utils& Utils :: getInstance() {
    static Utils instance;
    return instance;
}

SDL_Window* Utils :: getWindow() {
    return window;
}

SDL_Renderer* Utils :: getRenderer() {
    return renderer;
}

void Utils :: initSDL() {
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    font = TTF_OpenFont(FONTS_PATH"MuseoSans500.otf", 33);
    font1 = TTF_OpenFont(FONTS_PATH"MuseoSans500.otf", 24);
}

void Utils :: quitSDL() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

SDL_Texture* Utils::loadImage(const std :: string &path) {
    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);   
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

SDL_Texture* Utils::loadText(const std::string& text, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* Utils :: loadStats(const std::string& text, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font1, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
    SDL_FreeSurface(surface);
    return texture;
}


