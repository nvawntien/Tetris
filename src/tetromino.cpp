#include "tetromino.h"

/*
    0 1 2 3 
    4 5 6 7
*/

point temp[4], backup[4], ghost[4];
int grid[CELL_HEIGHT][CELL_WIDTH] = {{0}};
std :: deque <int> previewQueue;

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
    initQueue();
}

// trộn ngẫu nhiễn các khối
void Tetromino :: refillBag() {
    bag = {0, 1, 2, 3, 4, 5, 6}; 
    unsigned seed = std::time(0);
    std::shuffle(bag.begin(), bag.end(), std::default_random_engine(seed)); // Trộn ngẫu nhiên các khối
    bagIndex = 0;
}

void Tetromino::initQueue() {
    for (int i = 0; i < 3; ++i) {
        if (bagIndex >= bag.size()) refillBag();
        previewQueue.push_back(bag[bagIndex++]);
    }
}

void Tetromino :: nextTetromino() {
    int id = previewQueue.front();
    previewQueue.pop_front();

    color = id + 1;
    std :: cerr << id << ' ' << color << '\n';
    
    for (int i = 0; i < 4; i++) {
        temp[i].x = figure[id][i] % 4  + 3;
        temp[i].y = figure[id][i] / 4;
    }

    if (bagIndex >= bag.size()) refillBag();
    previewQueue.push_back(bag[bagIndex++]);
}

void Tetromino :: reset() {
    for (int i = 0; i < 4; i++) {
        temp[i].x = figure[color-1][i] % 4 + 3;
        temp[i].y = figure[color-1][i] / 4;
    }
}

bool Tetromino :: checkCollision(const point (&positions)[4]) {
    for (int i = 0; i < 4; i++) {
        if (positions[i].x < 0 || positions[i].x >= CELL_WIDTH || positions[i].y >= CELL_HEIGHT || positions[i].y < 0) {
            return true;
        }
        // va cham voi block khac
        if (grid[positions[i].y][positions[i].x]) {
            return true;
        }
    }

    return false;
}

void Tetromino::rotate() {
    point pivot = temp[(bag[bagIndex-1] == 0) ? 1 : 2]; // chọn ô thứ 3 làm tâm xoay
    for (int i = 0; i < 4; i++) {
        int x = temp[i].x - pivot.x;
        int y = temp[i].y - pivot.y;

        temp[i].x = pivot.x - y;
        temp[i].y = pivot.y + x;
    }

    if (checkCollision(temp)) {
        // thử wall kick đơn giản
        const int kicks[] = {-1, 1, -2, 2};  // thử dịch sang trái/phải 1–2 ô

        for (int k = 0; k < 4; ++k) {
            for (int i = 0; i < 4; ++i) temp[i].x += kicks[k];
            if (!checkCollision(temp)) return; // nếu hợp lệ thì giữ nguyên
            for (int i = 0; i < 4; ++i) temp[i].x -= kicks[k]; // hoàn tác

        }

        // nếu không hợp lệ sau khi thử tất cả, thì hủy xoay
        for (int i = 0; i < 4; i++) temp[i] = backup[i];
    }
}
