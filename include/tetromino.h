#ifndef TETROMINO_H
#define TETROMINO_H
#include "utils.h"

struct point {
    int x, y;
};

extern point temp[4], backup[4], ghost[4];
extern int grid[CELL_HEIGHT][CELL_WIDTH];
extern std :: deque <int> previewQueue;

class Tetromino {
    public:
        Tetromino();
        int color;
        bool locked = false;
        bool flashing = false;
        Uint32 flashStartTime = 0;
        Uint32 flashDuration = 1000; // Thời gian nhấp nháy (milliseconds)
        void nextTetromino();
        void rotate();
        void reset();
        bool checkCollision(const point (&positions)[4]);
    private:
        static const int figure[7][4];
        std :: vector <int> bag;
        int bagIndex;
        void refillBag();
        void initQueue();
};

#endif