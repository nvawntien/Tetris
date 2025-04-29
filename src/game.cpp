#include "game.h"

Game :: Game() {
    Utils :: getInstance().initSDL();
    Utils :: getInstance().loadHighScores(HIGHSCORE_PATH, highScores);
    AssetManager :: getInstance().loadAssets();
    RectLayout :: getInstance().CreateRect();
    gameState = MENU;
}

bool Game :: isRunning() {
    return running;
}

void Game :: ResetGame() {
    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            grid[i][j] = 0;
        }
    }

    currentBlock.nextTetromino();
    hasHold = false;
    holdUsed = false;
    move_x = 0;
    score = 0;
    linesCleared = 0;
}

bool Game::Menu() {
    isGameRunning = true;
    isPauseRunning = true;
    isGameOverRunning = true;
    level = 1;
    ResetGame();
    Mix_HaltMusic();

    SDL_Event event;
    const SDL_Rect& playRect = RectLayout::getInstance().getButtonPlayRect();
    const SDL_Rect& levelRect = RectLayout::getInstance().getButtonLevelRect();

    ButtonState playState = NORMAL;
    ButtonState levelState = NORMAL;

    while (isMenuRunning) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        SDL_Point mousePoint = { mx, my };

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    isMenuRunning = false;
                    break;

                case SDL_MOUSEMOTION:
                    playState = SDL_PointInRect(&mousePoint, &playRect) ? HOVER : NORMAL;
                    levelState = SDL_PointInRect(&mousePoint, &levelRect) ? HOVER : NORMAL;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (SDL_PointInRect(&mousePoint, &playRect)) playState = DOWN;
                        if (SDL_PointInRect(&mousePoint, &levelRect)) levelState = DOWN;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (playState == DOWN && SDL_PointInRect(&mousePoint, &playRect)) {
                            gameState = PLAYING;
                            AssetManager :: getInstance().OpenBackgroundMusic();
                            isMenuRunning = false;
                        }

                        if (levelState == DOWN && SDL_PointInRect(&mousePoint, &levelRect)) {
                            level++;
                            if (level == 4) level = 1;
                        }

                        // Reset lại trạng thái nút sau khi nhả chuột
                        playState = NORMAL;
                        levelState = NORMAL;
                    }
                    break;
            }
        }
        AssetManager::getInstance().RenderAssetMenu(playState, levelState, level, highScores);
    }

    return isMenuRunning;
}


void Game :: setCurrentTime(Uint32 T) {
    currentTime = T;
}

void Game :: PerformHoldBlock() {
    if (!hasHold) {
        holdBlock = currentBlock.color;
        currentBlock.nextTetromino();
        holdUsed = false;
        hasHold = true;
    } 
    else {
        std :: swap(currentBlock.color, holdBlock);
        currentBlock.reset();
    }
}

void Game :: Event() {
    SDL_Event event;
   
    int mx, my;
    SDL_GetMouseState(&mx, &my);
    SDL_Point mousePoint = { mx, my };
   
    const SDL_Rect& pauseRect = RectLayout :: getInstance().getButtonPauseRect();

    while (SDL_PollEvent(&event)) {
       if (event.type == SDL_QUIT) {
            running = false;
            isGameRunning = false; 
       }
       else if (event.type == SDL_MOUSEMOTION) {
            pauseState = SDL_PointInRect(&mousePoint, &pauseRect) ? HOVER : NORMAL;
       }
       else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                if (SDL_PointInRect(&mousePoint, &pauseRect)) pauseState = DOWN;
            }
       }
       else if (event.type == SDL_MOUSEBUTTONUP) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                if (pauseState == DOWN && SDL_PointInRect(&mousePoint, &pauseRect)) {
                    gameState = PAUSING;
                    Mix_PauseMusic();
                    isGameRunning = false;
                }
            }
            pauseState = NORMAL;
       }
       else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) 
            {
            case SDLK_RIGHT:
                move_x = 1;
                AssetManager :: getInstance().OpenSoundEffect(MOVE);
                break;
            case SDLK_LEFT:
                move_x = -1;
                AssetManager :: getInstance().OpenSoundEffect(MOVE);
                break;
            case SDLK_DOWN:
                delay = 0;
                AssetManager :: getInstance().OpenSoundEffect(MOVE);
                break;
            case SDLK_UP:
                rotate = true;
                AssetManager :: getInstance().OpenSoundEffect(ROTATE);
                break;
            case SDLK_SPACE:
                hardDrop = true;
                AssetManager :: getInstance().OpenSoundEffect(HARD_DROP);
                break;
            case SDLK_c:
                AssetManager :: getInstance().OpenSoundEffect(HOLD);
                if (!holdUsed) {
                    PerformHoldBlock();
                    holdUsed = true;
                }
                break;
            }
       }
    }
}

void Game :: processGameLogic() {
    // save currentBlock
    for (int i = 0; i < 4; i++) backup[i] = temp[i];
     // move 
    for (int i = 0; i < 4; i++) {
        temp[i].x += move_x;
    }

    if (currentBlock.checkCollision(temp)) {
        for (int i = 0; i < 4; i++) temp[i] = backup[i];
    }

    if (rotate) currentBlock.rotate();

    if (hardDrop) {
        while (!currentBlock.checkCollision(temp)) {
            for (int i = 0; i < 4; i++) temp[i].y++;
        }

        for (int i = 0; i < 4; i++) temp[i].y--;
        for (int i = 0; i < 4; i++) {
            grid[temp[i].y][temp[i].x] = currentBlock.color;
        }
        currentBlock.nextTetromino();
        hardDrop = false;
        holdUsed = false;
    }
    else if (currentTime - lastTime > delay) {
        lastTime = currentTime;
        for (int i = 0; i < 4; i++) {
            temp[i].y += 1;
        }

        if (currentBlock.checkCollision(temp)) {
            for (int i = 0; i < 4; i++) {
                grid[backup[i].y][backup[i].x] = currentBlock.color; // save color
            }
            currentBlock.nextTetromino();
            holdUsed = false;
        }
    }

    move_x = 0;
    if (level == 1) delay = 500;
    else if (level == 2) delay = 300;
    else delay = 100;
    rotate = false;
}

void Game :: clearFullLines() {
    int currentlinesCleared = 0;

    for (int y = CELL_HEIGHT - 1; y >= 0; y--) {
        bool full = true;

        for (int x = 0; x < CELL_WIDTH; x++) {
            if (grid[y][x] == 0) {
                full = false;
                break;
            }
        }

        if (full) {
            AssetManager :: getInstance().OpenSoundEffect(LINE_CLEAR);
            currentlinesCleared++;
            // dời tất cả dòng bên trên xuống dưới
            for (int row = y; row > 0; row--) {
                for (int col = 0; col < CELL_WIDTH; col++) {
                    grid[row][col] = grid[row-1][col];
                }
            }

            // reset dòng đầu về 0
            for (int x = 0; x < CELL_WIDTH; x++) {
                grid[0][x] = 0;
            }

            // check dòng hiện tại
            y++;
        }
    }
    // calculate scores
    linesCleared += currentlinesCleared;
    switch (currentlinesCleared) {
        case 1: score += 40 * (level + 1); break;
        case 2: score += 100 * (level + 1); break;
        case 3: score += 300 * (level + 1); break;
        case 4: score += 1200 * (level + 1); break;
        default: break;
    }
}

void Game :: checkGameOver() {
    int game_over_count = 0;
    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            if (grid[i][j]) {
                game_over_count++; 
                break;
            }
        }
    }

    if (game_over_count == CELL_HEIGHT) {
        isGameRunning = false;
        gameState = GAME_OVER;
        AssetManager :: getInstance().OpenSoundEffect(GAMEOVER);
        Utils :: getInstance().updateHighScores(score, highScores);
        Utils :: getInstance().saveHighScores(HIGHSCORE_PATH, highScores);
    }
}

void Game :: updateRenderer() {
    SDL_RenderClear(Utils :: getInstance().getRenderer());  
    AssetManager :: getInstance().RenderAssetGame(score, level, linesCleared, pauseState);

    // render hold block
    if (hasHold) {
        AssetManager :: getInstance().RenderHoldBlock(holdBlock);
    }
    // render next block
    for (int i = 0; i < 3; i++) {
        AssetManager :: getInstance().RenderNextBlock(previewQueue[i]+1, i);
    }

    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            if (grid[i][j]) {
                AssetManager :: getInstance().RenderLockedBlock(j, i, grid[i][j]);
            }
        }
    }
    
    // render ghost block

    for (int i = 0; i < 4; i++) ghost[i] = temp[i];
   
    while (!currentBlock.checkCollision(ghost)) {
        for (int i = 0; i < 4; i++) ghost[i].y++;
    }
    
    for (int i = 0; i < 4; i++) ghost[i].y--;
    
    for (int i = 0; i < 4; i++) {
        AssetManager :: getInstance().RenderGhostBlock(ghost[i].x, ghost[i].y, currentBlock.color);
    }

    for (int i = 0; i < 4; i++) {
        AssetManager :: getInstance().RenderNormalBlock(temp[i].x, temp[i].y, currentBlock.color);
    }

    SDL_RenderPresent(Utils :: getInstance().getRenderer());
}

bool Game :: GamePlay() {
    isMenuRunning = true;
    isPauseRunning = true;
    isGameOverRunning = true;

    while (isGameRunning) {
        setCurrentTime(SDL_GetTicks());
        Event();
        processGameLogic();
        clearFullLines();
        checkGameOver();
        updateRenderer();        
    }

    return isGameRunning; 
}

bool Game :: GamePause() {
    isMenuRunning = true;
    isGameRunning = true;
    isGameOverRunning = true;

    SDL_Event event;

    ButtonState resumeState = NORMAL;
    ButtonState quitState = NORMAL;

    const SDL_Rect& resumeRect = RectLayout :: getInstance().getButtonResumeRect();
    const SDL_Rect& quitRect = RectLayout :: getInstance().getButtonQuitRect();

    while (isPauseRunning) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        SDL_Point mousePoint = { mx, my };

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    isPauseRunning = false;
                    break;

                case SDL_MOUSEMOTION:
                    resumeState = SDL_PointInRect(&mousePoint, &resumeRect) ? HOVER : NORMAL;
                    quitState = SDL_PointInRect(&mousePoint, &quitRect) ? HOVER : NORMAL;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (SDL_PointInRect(&mousePoint, &resumeRect)) resumeState = DOWN;
                        if (SDL_PointInRect(&mousePoint, &quitRect)) quitState = DOWN;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (resumeState == DOWN && SDL_PointInRect(&mousePoint, &resumeRect)) {
                            gameState = PLAYING;
                            Mix_ResumeMusic();
                            isPauseRunning = false;
                        }

                        if (quitState == DOWN && SDL_PointInRect(&mousePoint, &quitRect)) {
                            gameState = MENU;
                            isPauseRunning = false;
                        }

                        // Reset lại trạng thái nút sau khi nhả chuột
                        resumeState = NORMAL;
                        quitState = NORMAL;
                    }
                    break;
            }
        }
        SDL_RenderClear(Utils :: getInstance().getRenderer());
        AssetManager::getInstance().RenderAssetGame(score, level, linesCleared, pauseState);
        AssetManager::getInstance().RenderAssetPause(resumeState, quitState);
        SDL_RenderPresent(Utils :: getInstance().getRenderer());
    }


    return isPauseRunning;    
}

bool Game :: GameOver() {
    Mix_HaltMusic();
    isMenuRunning = true;
    isGameRunning = true;
    isPauseRunning = true;

    SDL_Event event;

    ButtonState homeState = NORMAL;
    ButtonState replayState = NORMAL;

    const SDL_Rect& homeRect = RectLayout :: getInstance().getButtonHomeRect();
    const SDL_Rect& replayRect = RectLayout :: getInstance().getButtonReplayRect();

    while (isGameOverRunning) {
        int mx, my;
        SDL_GetMouseState(&mx, &my);
        SDL_Point mousePoint = { mx, my };

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    isGameOverRunning = false;
                    break;

                case SDL_MOUSEMOTION:
                    homeState = SDL_PointInRect(&mousePoint, &homeRect) ? HOVER : NORMAL;
                    replayState = SDL_PointInRect(&mousePoint, &replayRect) ? HOVER : NORMAL;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (SDL_PointInRect(&mousePoint, &homeRect)) homeState = DOWN;
                        if (SDL_PointInRect(&mousePoint, &replayRect)) replayState = DOWN;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (homeState == DOWN && SDL_PointInRect(&mousePoint, &homeRect)) {
                            gameState = MENU;
                            isGameOverRunning = false;
                        }

                        if (replayState == DOWN && SDL_PointInRect(&mousePoint, &replayRect)) {
                            gameState = PLAYING;
                            ResetGame();
                            AssetManager :: getInstance().OpenBackgroundMusic();
                            isGameOverRunning = false;
                        }

                        // Reset lại trạng thái nút sau khi nhả chuột
                        homeState = NORMAL;
                        replayState = NORMAL;
                    }
                    break;
            }
        }
        SDL_RenderClear(Utils :: getInstance().getRenderer());
        AssetManager::getInstance().RenderAssetGame(score, level, linesCleared, pauseState);
        AssetManager::getInstance().RenderAssetGameOver(homeState, replayState, highScores);
        SDL_RenderPresent(Utils :: getInstance().getRenderer());
    }


    return isGameOverRunning;    
}

