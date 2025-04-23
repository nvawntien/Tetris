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


    Block[I] = Utils :: getInstance().loadImage(NORMAL_PATH I_PNG);
    Block[Z] = Utils :: getInstance().loadImage(NORMAL_PATH Z_PNG);
    Block[J] = Utils :: getInstance().loadImage(NORMAL_PATH J_PNG);
    Block[L] = Utils :: getInstance().loadImage(NORMAL_PATH L_PNG);
    Block[O] = Utils :: getInstance().loadImage(NORMAL_PATH O_PNG);
    Block[S] = Utils :: getInstance().loadImage(NORMAL_PATH S_PNG);
    Block[T] = Utils :: getInstance().loadImage(NORMAL_PATH T_PNG);

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
    SDL_RenderCopy(renderer, Image[BACKGROUND], NULL, nullptr);
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

void AssetManager :: RenderBlock(int x, int y, int color) {
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Block[color], NULL, &(RectLayout :: getInstance().getBlockRect(x, y)));
}

void AssetManager ::  clean() {
    for (auto &pair : Image) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Text) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Block) {
        SDL_DestroyTexture(pair.second);
    }

    Block.clear();
    Image.clear();
    Text.clear();
}
