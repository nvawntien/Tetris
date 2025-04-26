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

    
    mainLogoRect = {LOGO_POS_X, LOGO_POS_Y, LOGO_WIDTH, LOGO_HEIGHT};
    buttonPlayRect = {BUTTON_PLAY_POS_X, BUTTON_PLAY_POS_Y, BUTTON_PLAY_WIDTH, BUTTON_PLAY_HEIGHT};
    buttonLevelRect = {buttonPlayRect.x, buttonPlayRect.y + 60 + BLOCK_SIZE / 2, BUTTON_PLAY_WIDTH, BUTTON_PLAY_HEIGHT};
    matrix = {MATRIX_POS_X, MATRIX_POS_Y, MATRIX_WIDTH, MATRIX_HEIGHT};
    buttonPauseRect = {BUTTON_PAUSE_POS_X, BUTTON_PAUSE_POS_Y, BUTTON_PAUSE_WIDTH, BUTTON_PAUSE_HEIGHT};
    
    scoreRect = {SCORE_POS_X, SCORE_POS_Y, SCORE_WIDTH, SCORE_HEIGHT};
    levelRect = {scoreRect.x, scoreRect.y + 60 ,scoreRect.w, scoreRect.h};
    linesRect = {levelRect.x, levelRect.y + 60, scoreRect.w, scoreRect.h};
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

SDL_Rect& RectLayout :: getButtonLevelRect() {
    return buttonLevelRect;
}

SDL_Rect& RectLayout :: getMatrixRect() {
    return matrix;
}

SDL_Rect& RectLayout :: getNextRect(SDL_Texture* texture, int i) {
    int _w = 0, _h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &_w, &_h);
    int xx = QUEUE_POS_X + (BLOCK_WIDTH - _w) / 2;
    int yy = QUEUE_POS_Y + (i * BLOCK_HEIGHT) + (BLOCK_HEIGHT - _h) / 2;

    queueRect[i] = {xx, yy, _w, _h};
    return queueRect[i];
}

SDL_Rect& RectLayout :: getTextPlayRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = buttonPlayRect.x + (buttonPlayRect.w - texW) / 2;
    int yy = buttonPlayRect.y + (buttonPlayRect.h - texH) / 2;
    textPlayRect = {xx, yy, texW, texH};
    return textPlayRect;
}

SDL_Rect& RectLayout :: getTextLevelRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = buttonLevelRect.x + (buttonLevelRect.w - texW) / 2;
    int yy = buttonLevelRect.y + (buttonLevelRect.h - texH) / 2;
    textLevelRect = {xx, yy, texW, texH};
    return textLevelRect;
}

SDL_Rect& RectLayout :: getButtonPauseRect() {
    return buttonPauseRect;
}

SDL_Rect& RectLayout :: getScoreRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = scoreRect.x + (scoreRect.w - texW) / 2;
    int yy = scoreRect.y + (scoreRect.h - texH) / 2;
    scoreTextRect = {xx, yy, texW, texH};
    return scoreTextRect;
}

SDL_Rect& RectLayout :: getLevelRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = levelRect.x + (levelRect.w - texW) / 2;
    int yy = levelRect.y + (levelRect.h - texH) / 2;
    levelTextRect = {xx, yy, texW, texH};
    return levelTextRect;
}

SDL_Rect& RectLayout :: getLinesRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = linesRect.x + (linesRect.w - texW) / 2;
    int yy = linesRect.y + (linesRect.h - texH) / 2;
    linesTextRect = {xx, yy, texW, texH};
    return linesTextRect;
}