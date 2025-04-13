#include "tetromino.h"

/*
    0 1 2 3 
    4 5 6 7
*/

point temp[4], backup[4];
int grid[CELL_HEIGHT][CELL_WIDTH] = {{0}};

const int Tetromino :: figure[7][4] = {
    {0, 1, 2, 3}, // I
    {0, 1, 5, 6}, // Z
    {0, 4, 5, 6}, // J
    {2, 6, 5, 4}, // L
    {1, 2, 5, 6}, // O
    {2, 1, 5, 4}, // S
    {1, 4, 5, 6}  // T
};

Tetromino :: Tetromino() {
    bagIndex = 0;
    refillBag();
    nextTetromino();
}

void Tetromino :: refillBag() {
    bag = {0, 1, 2, 3, 4, 5, 6}; 
    unsigned seed = std::time(0);
    std::shuffle(bag.begin(), bag.end(), std::default_random_engine(seed)); // Trộn ngẫu nhiên các khối
    bagIndex = 0;
}

void Tetromino :: nextTetromino() {
    if (bagIndex >= bag.size()) {
        refillBag();
    }

    int random = bag[bagIndex++];
    color = random + 1;

    for (int i = 0; i < 4; i++) {
        temp[i].x = figure[random][i] % 4  + 3;
        temp[i].y = figure[random][i] / 4;
    }
}

bool Tetromino :: checkCollision() {
    for (int i = 0; i < 4; i++) {
        if (temp[i].x < 0 || temp[i].x >= CELL_WIDTH || temp[i].y >= CELL_HEIGHT) {
            return true;
        }
        // va cham voi block khac
        if (grid[temp[i].y][temp[i].x]) {
            return true;
        }
    }

    return false;
}

void Tetromino::rotate() {
    point pivot = temp[2]; // chọn ô thứ 3 làm tâm xoay
    for (int i = 0; i < 4; i++) {
        int x = temp[i].x - pivot.x;
        int y = temp[i].y - pivot.y;

        temp[i].x = pivot.x - y;
        temp[i].y = pivot.y + x;
    }

    if (checkCollision()) {
        // thử wall kick đơn giản
        const int kicks[] = {-1, 1, -2, 2};  // thử dịch sang trái/phải 1–2 ô
        for (int k = 0; k < 4; ++k) {
            for (int i = 0; i < 4; ++i) temp[i].x += kicks[k];
            if (!checkCollision()) return; // nếu hợp lệ thì giữ nguyên
            for (int i = 0; i < 4; ++i) temp[i].x -= kicks[k]; // hoàn tác
        }

        // nếu không hợp lệ sau khi thử tất cả, thì hủy xoay
        for (int i = 0; i < 4; i++) temp[i] = backup[i];
    }
}
