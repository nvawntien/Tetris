#include "game.h"

bool Game :: initGame() {
    util.initSDL(&util.window, &util.renderer);
    SDL_SetRenderDrawColor(util.renderer, 255, 255, 255, 255);
    return true;
}

bool Game :: menu() {
    return running;
}

void Game :: Event() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
            break;
        }
    }
}