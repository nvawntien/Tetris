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

    for (int i = 0; i < 5; i++) {
        menu_HighScore[i] = {m_LINE_POS_X, m_LINE_POS_Y + i * LINE_HEIGHT, LINE_WIDTH, LINE_HEIGHT};
        gameOver_HighScore[i] = {g_o_LINE_POS_X, g_o_LINE_POS_Y + i * LINE_HEIGHT, LINE_WIDTH, LINE_HEIGHT};
    }


    mainLogoRect = {LOGO_POS_X, LOGO_POS_Y, LOGO_WIDTH, LOGO_HEIGHT};
    matrix = {MATRIX_POS_X, MATRIX_POS_Y, MATRIX_WIDTH, MATRIX_HEIGHT};
    menuFrameRect = {MENU_FRAME_POS_X, MENU_FRAME_POS_Y, MENU_FRAME_WIDTH, MENU_FRAME_HEIGHT};
    menuGameOverRect = {GAME_OVER_POS_X, GAME_OVER_POS_Y, GAME_OVER_WIDTH, GAME_OVER_HEIGHT};
    
    buttonPlayRect = {BUTTON_PLAY_POS_X, BUTTON_PLAY_POS_Y, BUTTON_PLAY_WIDTH, BUTTON_PLAY_HEIGHT};
    buttonLevelRect = {buttonPlayRect.x, buttonPlayRect.y + 60 + BLOCK_SIZE / 2, BUTTON_PLAY_WIDTH, BUTTON_PLAY_HEIGHT};
    buttonResumeRect = {BUTTON_RESUME_POS_X, BUTTON_RESUME_POS_Y, BUTTON_RESUME_WIDTH, BUTTON_RESUME_HEIGHT};
    buttonQuitRect = {buttonResumeRect.x, buttonResumeRect.y + BUTTON_RESUME_HEIGHT + BLOCK_SIZE, buttonResumeRect.w, buttonResumeRect.h};
    buttonPauseRect = {BUTTON_PAUSE_POS_X, BUTTON_PAUSE_POS_Y, BUTTON_PAUSE_WIDTH, BUTTON_PAUSE_HEIGHT};
    buttonHomeRect = {BUTTON_HOME_POS_X, BUTTON_HOME_POS_Y, BUTTON_HOME_SIZE, BUTTON_HOME_SIZE};
    buttonReplayRect = {buttonHomeRect.x + 80, buttonHomeRect.y, buttonHomeRect.w, buttonHomeRect.h};

    iconHomeRect = {buttonHomeRect.x + 5, buttonHomeRect.y + 5, 30, 30};
    iconReplayRect = {buttonReplayRect.x + 5, buttonReplayRect.y + 5, 30, 30};
    highScoreRect = {HIGH_SCORE_POS_X, HIGH_SCORE_POS_Y, HIGH_SCORE_WIDTH, HIGH_SCORE_HEIGHT};

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

SDL_Rect& RectLayout :: getMatrixRect() {
    return matrix;
}

SDL_Rect& RectLayout :: getHighScoreRect() {
    return highScoreRect;
}

SDL_Rect& RectLayout :: getMenuGameOverRect() {
    return menuGameOverRect;
}

SDL_Rect& RectLayout :: getButtonPlayRect() {
    return buttonPlayRect;
}

SDL_Rect& RectLayout :: getButtonLevelRect() {
    return buttonLevelRect;
}

SDL_Rect& RectLayout :: getButtonResumeRect() {
    return buttonResumeRect;
}

SDL_Rect& RectLayout :: getButtonQuitRect() {
    return buttonQuitRect;
}

SDL_Rect& RectLayout :: getButtonHomeRect() {
    return buttonHomeRect;
}

SDL_Rect& RectLayout :: getButtonReplayRect() {
    return buttonReplayRect; 
}

SDL_Rect& RectLayout :: getMenuFrameRect() {
    return menuFrameRect;
}

SDL_Rect& RectLayout :: getIconHomeRect() {
    return iconHomeRect;
}

SDL_Rect& :: RectLayout :: getIconReplayRect() {
    return iconReplayRect;
}

SDL_Rect& RectLayout :: getHoldRect(SDL_Texture* texture) {
    int _w = 0, _h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &_w, &_h);
    int xx = HOLD_POS_X + (BLOCK_WIDTH - _w) / 2;
    int yy = HOLD_POS_Y + (BLOCK_HEIGHT - _h) / 2;

    holdRect = {xx, yy, _w, _h};
    return holdRect;
}

SDL_Rect& RectLayout :: getNextRect(SDL_Texture* texture, int i) {
    int _w = 0, _h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &_w, &_h);
    int xx = QUEUE_POS_X + (BLOCK_WIDTH - _w) / 2;
    int yy = QUEUE_POS_Y + (i * BLOCK_HEIGHT) + (BLOCK_HEIGHT - _h) / 2;

    queueRect[i] = {xx, yy, _w, _h};
    return queueRect[i];
}

SDL_Rect& RectLayout :: getPlayTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = buttonPlayRect.x + (buttonPlayRect.w - texW) / 2;
    int yy = buttonPlayRect.y + (buttonPlayRect.h - texH) / 2;
    playTextRect= {xx, yy, texW, texH};
    return playTextRect;
}

SDL_Rect& RectLayout :: getLevelTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = buttonLevelRect.x + (buttonLevelRect.w - texW) / 2;
    int yy = buttonLevelRect.y + (buttonLevelRect.h - texH) / 2;
    levelTextRect = {xx, yy, texW, texH};
    return levelTextRect;
}

SDL_Rect& RectLayout :: getResumeTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = buttonResumeRect.x + (buttonResumeRect.w - texW) / 2;
    int yy = buttonResumeRect.y + (buttonResumeRect.h - texH) / 2;
    resumeTextRect = {xx, yy, texW, texH};
    return resumeTextRect;
}

SDL_Rect& RectLayout :: getQuitTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = buttonQuitRect.x + (buttonQuitRect.w - texW) / 2;
    int yy = buttonQuitRect.y + (buttonQuitRect.h - texH) / 2;
    quitTextRect = {xx, yy, texW, texH};
    return quitTextRect;
}

SDL_Rect& RectLayout :: getButtonPauseRect() {
    return buttonPauseRect;
}

SDL_Rect& RectLayout :: getScoreTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = scoreRect.x + (scoreRect.w - texW) / 2;
    int yy = scoreRect.y + (scoreRect.h - texH) / 2;
    scoreTextRect = {xx, yy, texW, texH};
    return scoreTextRect;
}

SDL_Rect& RectLayout :: getLevelMiniTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = levelRect.x + (levelRect.w - texW) / 2;
    int yy = levelRect.y + (levelRect.h - texH) / 2;
    levelMiniTextRect = {xx, yy, texW, texH};
    return levelMiniTextRect;
}

SDL_Rect& RectLayout :: getLinesTextRect(SDL_Texture* texture) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = linesRect.x + (linesRect.w - texW) / 2;
    int yy = linesRect.y + (linesRect.h - texH) / 2;
    linesTextRect = {xx, yy, texW, texH};
    return linesTextRect;
}

SDL_Rect& RectLayout :: getMenuHighScoreTextRect(SDL_Texture* texture, int i) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = menu_HighScore[i].x + (menu_HighScore[i].w - texW) / 2;
    int yy = menu_HighScore[i].y + (menu_HighScore[i].h - texH) / 2;
    highScoreTextRect[i] = {xx, yy, texW, texH};
    return highScoreTextRect[i];
}

SDL_Rect& RectLayout :: getGameOverHighScoreTextRect(SDL_Texture* texture, int i) {
    int texW = 0, texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    int xx = gameOver_HighScore[i].x + (gameOver_HighScore[i].w - texW) / 2;
    int yy = gameOver_HighScore[i].y + (gameOver_HighScore[i].h - texH) / 2;
    highScoreTextRect[i] = {xx, yy, texW, texH};
    return highScoreTextRect[i];
}

