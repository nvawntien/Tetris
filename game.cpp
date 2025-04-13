#include "game.h"

Game :: Game() {
    Utils :: getInstance().initSDL();
    AssetManager :: getInstance().loadAssets();
    RectLayout :: getInstance().CreateRect();
    gameState = MENU;
}

bool Game :: isRunning() {
    return running;
}

bool Game::Menu() {
    SDL_Event event;

    const SDL_Rect& playRect = RectLayout::getInstance().getButtonPlayRect();
    const SDL_Rect& levelRect = RectLayout::getInstance().getButtonLeverRect();

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
        AssetManager::getInstance().RenderAssetMenu(playState, levelState, level);
    }

    return isMenuRunning;
}


void Game :: setCurrentTime(Uint32 T) {
    currentTime = T;
}

void Game :: Event() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
       if (event.type == SDL_QUIT) {
            running = false;
            isGameRunning = false;
       }
       else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) 
            {
            case SDLK_RIGHT:
                move_x = 1;
                break;
            case SDLK_LEFT:
                move_x = -1;
                break;
            case SDLK_DOWN:
                delay = 0;
                break;
            case SDLK_UP:
                rotate = true;
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

    if (currentBlock.checkCollision()) {
        for (int i = 0; i < 4; i++) temp[i] = backup[i];
    }

    if (rotate) currentBlock.rotate();

    if (currentTime - lastTime > delay) {
        lastTime = currentTime;
        for (int i = 0; i < 4; i++) {
            temp[i].y += 1;
        }

        if (currentBlock.checkCollision()) {
            for (int i = 0; i < 4; i++) {
                grid[backup[i].y][backup[i].x] = currentBlock.color; // save color
            }
            currentBlock.nextTetromino();
        }
    }

    move_x = 0;
    if (level == 1) delay = 500;
    else if (level == 2) delay = 300;
    else delay = 200;
    rotate = false;
}

void Game :: clearFullLines() {
    for (int y = CELL_HEIGHT - 1; y >= 0; y--) {
        bool full = true;

        for (int x = 0; x < CELL_WIDTH; x++) {
            if (grid[y][x] == 0) {
                full = false;
                break;
            }
        }

        if (full) {
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
    }
}

void Game :: updateRenderer() {
    SDL_RenderClear(Utils :: getInstance().getRenderer());  
    AssetManager :: getInstance().RenderAssetGame();

    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            if (grid[i][j]) {
                AssetManager :: getInstance().RenderBlock(j, i, grid[i][j]);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        AssetManager :: getInstance().RenderBlock(temp[i].x, temp[i].y, currentBlock.color);
    }

    SDL_RenderPresent(Utils :: getInstance().getRenderer());
}

bool Game :: GamePlay() {
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
    return true;
}

bool Game :: GameOver() {
    return true;
}

