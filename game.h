#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include "AssetManager.h"
#include "tetromino.h"

enum GameState {
    MENU,
    PLAYING,
    PAUSE,
    GAME_OVER
};

class Game {
    public:
        Game();
        GameState gameState;
        bool isRunning();
        bool Menu();
        bool GamePlay();
        bool GamePause();
        bool GameOver();
    private:
        void setCurrentTime(Uint32 T);
        void Event();
        void processGameLogic();
        void clearFullLines();
        void checkGameOver();
        void updateRenderer();
        bool running = true, isGameRunning = true, isMenuRunning = true;
        Uint32 currentTime = 0, lastTime = 0, delay = 500;
        Tetromino currentBlock;
        bool rotate = false;
        int move_x = 0;
        int level = 1;
};


#endif