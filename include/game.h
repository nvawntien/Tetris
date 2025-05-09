#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include "AssetManager.h"
#include "tetromino.h"

enum GameState {
    MENU,
    PLAYING,
    PAUSING,
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
        void ResetGame();
        void PerformHoldBlock();
        void setCurrentTime(Uint32 T);
        void Event();
        void processGameLogic();
        void clearFullLines();
        void checkGameOver();
        void updateRenderer();
        bool running = true, isGameRunning = true, isMenuRunning = true, isPauseRunning = true, isGameOverRunning = true;
        Uint32 currentTime = 0, lastTime = 0, delay = 500;
        Tetromino currentBlock;
        int holdBlock;
        ButtonState pauseState = NORMAL;
        bool holdUsed = false;
        bool hasHold = false;
        bool rotate = false;
        bool hardDrop = false;
        int move_x = 0;
        int level = 1;
        int score = 0;
        std :: vector <int>  highScores;
        int linesCleared = 0;
        
};


#endif