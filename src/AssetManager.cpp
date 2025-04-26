#include "AssetManager.h"

AssetManager& AssetManager :: getInstance() {
    static AssetManager instance;
    return instance;
}

void AssetManager :: loadAssets() {
    Image[BACKGROUND] = Utils :: getInstance().loadImage(BACKGROUND_PATH);
    Image[MATRIX] = Utils :: getInstance().loadImage(MATRIX_PATH);
    Image[LOGO] = Utils :: getInstance().loadImage(LOGO_PATH);
    Image[PLAY|NORMAL] = Utils :: getInstance().loadImage(NORMAL_PATH BUTTON_PLAY);
    Image[PLAY|HOVER] = Utils :: getInstance().loadImage(HOVER_PATH BUTTON_PLAY);
    Image[PLAY|DOWN] = Utils :: getInstance().loadImage(DOWN_PATH BUTTON_PLAY);
    Image[LEVEL|NORMAL] = Utils :: getInstance().loadImage(NORMAL_PATH BUTTON_LEVEL);
    Image[LEVEL|HOVER] = Utils :: getInstance().loadImage(HOVER_PATH BUTTON_LEVEL);
    Image[LEVEL|DOWN] = Utils :: getInstance().loadImage(DOWN_PATH BUTTON_LEVEL);
    Image[PAUSE|NORMAL] = Utils :: getInstance().loadImage(NORMAL_PATH BUTTON_PAUSE);
    Image[PAUSE|HOVER] = Utils :: getInstance().loadImage(HOVER_PATH BUTTON_PAUSE);
    Image[PAUSE|DOWN] = Utils :: getInstance().loadImage(DOWN_PATH BUTTON_PAUSE);


    Normal_Block[I] = Utils :: getInstance().loadImage(NORMAL_PATH I_PNG);
    Normal_Block[Z] = Utils :: getInstance().loadImage(NORMAL_PATH Z_PNG);
    Normal_Block[J] = Utils :: getInstance().loadImage(NORMAL_PATH J_PNG);
    Normal_Block[L] = Utils :: getInstance().loadImage(NORMAL_PATH L_PNG);
    Normal_Block[O] = Utils :: getInstance().loadImage(NORMAL_PATH O_PNG);
    Normal_Block[S] = Utils :: getInstance().loadImage(NORMAL_PATH S_PNG);
    Normal_Block[T] = Utils :: getInstance().loadImage(NORMAL_PATH T_PNG);
    
    Ghost_Block[I] = Utils :: getInstance().loadImage(GHOST_PATH I_PNG);
    Ghost_Block[Z] = Utils :: getInstance().loadImage(GHOST_PATH Z_PNG);
    Ghost_Block[J] = Utils :: getInstance().loadImage(GHOST_PATH J_PNG);
    Ghost_Block[L] = Utils :: getInstance().loadImage(GHOST_PATH L_PNG);
    Ghost_Block[O] = Utils :: getInstance().loadImage(GHOST_PATH O_PNG);
    Ghost_Block[S] = Utils :: getInstance().loadImage(GHOST_PATH S_PNG);
    Ghost_Block[T] = Utils :: getInstance().loadImage(GHOST_PATH T_PNG);

    Locked_Block[I] = Utils :: getInstance().loadImage(LOCKED_PATH I_PNG);
    Locked_Block[Z] = Utils :: getInstance().loadImage(LOCKED_PATH Z_PNG);
    Locked_Block[J] = Utils :: getInstance().loadImage(LOCKED_PATH J_PNG);
    Locked_Block[L] = Utils :: getInstance().loadImage(LOCKED_PATH L_PNG);
    Locked_Block[O] = Utils :: getInstance().loadImage(LOCKED_PATH O_PNG);
    Locked_Block[S] = Utils :: getInstance().loadImage(LOCKED_PATH S_PNG);
    Locked_Block[T] = Utils :: getInstance().loadImage(LOCKED_PATH T_PNG);

    Whole_Block[I] = Utils :: getInstance().loadImage(WHOLE_PATH I_PNG);
    Whole_Block[Z] = Utils :: getInstance().loadImage(WHOLE_PATH Z_PNG);
    Whole_Block[J] = Utils :: getInstance().loadImage(WHOLE_PATH J_PNG);
    Whole_Block[L] = Utils :: getInstance().loadImage(WHOLE_PATH L_PNG);
    Whole_Block[O] = Utils :: getInstance().loadImage(WHOLE_PATH O_PNG);
    Whole_Block[S] = Utils :: getInstance().loadImage(WHOLE_PATH S_PNG);
    Whole_Block[T] = Utils :: getInstance().loadImage(WHOLE_PATH T_PNG);

    SDL_Color color = {255, 255, 255, 255};
    Text[PLAY] = Utils :: getInstance().loadText("PLAY", color);
    Text[L1|TARGET] = Utils :: getInstance().loadText("LEVEL 1", color);
    Text[L2|TARGET] = Utils :: getInstance().loadText("LEVEL 2", color);
    Text[L3|TARGET] = Utils :: getInstance().loadText("LEVEL 3", color);
    
    Text[SCORE] = Utils :: getInstance().loadStats("0", color);
    Text[L1] = Utils :: getInstance().loadStats("1", color);
    Text[L2] = Utils :: getInstance().loadStats("2", color);
    Text[L3] = Utils :: getInstance().loadStats("3", color);
    Text[LINES] = Utils :: getInstance().loadStats("0", color);
}

void AssetManager::RenderAssetMenu(ButtonState playState, ButtonState levelState, int level) {
    SDL_Renderer* renderer = Utils::getInstance().getRenderer();
    SDL_RenderClear(renderer);

    // Vẽ nền và logo
    SDL_RenderCopy(renderer, Image[BACKGROUND], NULL, NULL);
    SDL_RenderCopy(renderer, Image[LOGO], NULL, &RectLayout::getInstance().getLogoRect());

    SDL_RenderCopy(renderer, Image[PLAY|playState], NULL, &RectLayout::getInstance().getButtonPlayRect());
    SDL_RenderCopy(renderer, Image[LEVEL|levelState], NULL, &RectLayout::getInstance().getButtonLevelRect());
    SDL_RenderCopy(renderer, Text[PLAY], NULL, &RectLayout :: getInstance().getTextPlayRect(Text[PLAY]));
    SDL_RenderCopy(renderer, Text[level|TARGET], NULL, &RectLayout :: getInstance().getTextLevelRect(Text[level|TARGET]));
    SDL_RenderPresent(renderer);
}


void AssetManager :: RenderAssetGame(int score, int level, int lines) {
    SDL_Renderer* renderer = Utils :: getInstance().getRenderer();
    SDL_RenderCopy(renderer, Image[BACKGROUND], NULL, NULL);
    SDL_RenderCopy(renderer, Image[MATRIX], NULL, &RectLayout :: getInstance().getMatrixRect());
    SDL_RenderCopy(renderer, Image[PAUSE|NORMAL], NULL, &RectLayout :: getInstance().getButtonPauseRect());
    

    SDL_RenderCopy(renderer, Text[level], NULL, &RectLayout :: getInstance().getLevelRect(Text[level]));
    
    // update score
    std::string scoreText = std::to_string(score);
    
    if (prevScore != score) {
        prevScore = score;
        Text[SCORE] = Utils :: getInstance().loadStats(scoreText, {255, 255, 255, 255});   
    }
    SDL_RenderCopy(renderer, Text[SCORE], NULL, &RectLayout :: getInstance().getScoreRect(Text[SCORE])); 

    std :: string lineClearedText = std::to_string(lines);

    if (prelineCleared != lines) {
        prelineCleared = lines;
        Text[LINES] = Utils :: getInstance().loadStats(lineClearedText, {255, 255, 255, 255});   
    }

    SDL_RenderCopy(renderer, Text[LINES], NULL, &RectLayout :: getInstance().getLinesRect(Text[LINES]));
}

void AssetManager :: RenderNextBlock(int color, int i) {
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Whole_Block[color], NULL, &RectLayout :: getInstance().getNextRect(Whole_Block[color], i));
}

void AssetManager :: RenderNormalBlock(int x, int y, int color) {
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Normal_Block[color], NULL, &RectLayout :: getInstance().getBlockRect(x, y));
}
 
void AssetManager :: RenderGhostBlock(int x, int y, int color) {
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Ghost_Block[color], NULL, &RectLayout :: getInstance().getBlockRect(x, y));
}

void AssetManager :: RenderLockedBlock(int x, int y, int color) {
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Locked_Block[color], NULL, &RectLayout :: getInstance().getBlockRect(x, y));
}

void AssetManager ::  clean() {
    for (auto &pair : Image) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Text) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Normal_Block) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Ghost_Block) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Whole_Block) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Locked_Block) {
        SDL_DestroyTexture(pair.second);
    }

    Locked_Block.clear();
    Whole_Block.clear();
    Normal_Block.clear();
    Ghost_Block.clear();
    Image.clear();
    Text.clear();
}
