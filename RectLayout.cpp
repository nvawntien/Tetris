#include "RectLayout.h"

RectLayout& RectLayout :: getInstance() {
    static RectLayout instance;
    return instance;
}

void RectLayout :: CreateRect() {
    for (int y = 0; y < CELL_HEIGHT; y++) {
        for (int x = 0; x < CELL_WIDTH; x++) {
            gridRects[y][x] = {
                gridOffsetx + x * BLOCK_SIZE + x,
                gridOffsety + y * BLOCK_SIZE + y,
                BLOCK_SIZE,
                BLOCK_SIZE
            };
        }
    }

    mainLogoRect = {(SCREEN_WIDTH - 240) / 2, (SCREEN_HEIGHT - CELL_HEIGHT * BLOCK_SIZE) / 2 + BLOCK_SIZE / 5, 240, 160};
    buttonPlayRect = {(SCREEN_WIDTH - 200) / 2, mainLogoRect.y + 160 + BLOCK_SIZE / 2, 200, 60};
    buttonLeverRect = {buttonPlayRect.x, buttonPlayRect.y + 60 + BLOCK_SIZE / 2, 200, 60};
    matrix = {(SCREEN_WIDTH - GRID_WIDTH) / 2, (SCREEN_HEIGHT - GRID_HEIGHT) / 2, GRID_WIDTH, GRID_HEIGHT};
    textPlayRect = {buttonPlayRect.x + 65, buttonPlayRect.y + 15, 70, 30};
    textLevelRect = {buttonLeverRect.x + 40, buttonLeverRect.y + 15, 120, 30};
}   

SDL_Rect& RectLayout :: getBlockRect(int x, int y) {
    return gridRects[y][x];
}

SDL_Rect& RectLayout :: getLogoRect() {
    return mainLogoRect;
}

SDL_Rect& RectLayout :: getButtonPlayRect() {
    return buttonPlayRect;
}

SDL_Rect& RectLayout :: getButtonLeverRect() {
    return buttonLeverRect;
}

SDL_Rect& RectLayout :: getMatrixRect() {
    return matrix;
}

SDL_Rect& RectLayout :: getTextPlayRect() {
    return textPlayRect;
}

SDL_Rect& RectLayout :: getTextLevelRect() {
    return textLevelRect;
}