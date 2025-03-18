#include "game.h"

void Game :: InitGame() {
    Util :: getInstance().initSDL();
    SDL_SetRenderDrawColor(Util :: getInstance().getRenderer(), 255, 255, 255, 255);
    AssetManager :: getInstance().loadAssets();
    AssetManager :: getInstance().InitButtonRect();
    gameState = MENU;
}

bool Game :: isRunning() {
    return running;
}

bool Game :: Menu() {
    SDL_Event event;

    AssetManager :: getInstance().RenderAssetMenu();

    bool isMenuRunning = true;
    while (isMenuRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                isMenuRunning = false;
            }
            // . . . handle input 
        }
    }
    
    return isMenuRunning;
}

bool Game :: GamePlay() {
    return true;
}

bool Game :: GamePause() {
    return true;
}

bool Game :: GameOver() {
    return true;
}

void Game :: Event() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
            break;
        }
    }
}

void Game :: Clean() {

}