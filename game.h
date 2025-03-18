#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include "AssetManager.h"

enum GameState {
    MENU,
    PLAYING,
    PAUSE,
    GAME_OVER
};

class Game {
    public:
        GameState gameState;
        void InitGame(); 
        bool isRunning();
        bool Menu();
        bool GamePlay();
        bool GamePause();
        bool GameOver();
        void Event();
        void Clean();
    private:
        bool running = true;
};

#endif