#ifndef GAME_H
#define GAME_H
#include "utils.h"

class Game {
    private:
        bool running = true;
    public:
        Util util;
        bool initGame();
        bool menu();
        bool isRunning() {
            return running;
        };
        void Event();
};

#endif