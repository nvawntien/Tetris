#ifndef TETROMINO_H
#define TETROMINO_H
#include "utils.h"

struct point {
    int x, y;
};

extern point temp[4], backup[4];
extern int grid[CELL_HEIGHT][CELL_WIDTH];

class Tetromino {
    public:
        Tetromino();
        int color;
        void nextTetromino();
        void rotate();
        bool checkCollision();
    private:
        static const int figure[7][4];
        std :: vector <int> bag;
        std :: deque <int> previewQueue;
        int bagIndex;
        void refillBag();
        void initQueue();
};

#endif