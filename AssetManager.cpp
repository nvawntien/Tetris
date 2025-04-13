#include "AssetManager.h"

AssetManager& AssetManager :: getInstance() {
    static AssetManager instance;
    return instance;
}

void AssetManager :: loadAssets() {
    Image["background"] = Utils :: getInstance().loadImage("img/background.png");
    Image["matrix"] = Utils :: getInstance().loadImage("img/matrix.png");
    Image["mainLogo"] = Utils :: getInstance().loadImage("img/main-logo.png");
    Image["button_play_normal"] = Utils :: getInstance().loadImage("img/button-play-normal.png");
    Image["button_play_hover"] = Utils :: getInstance().loadImage("img/button-play-hover.png");
    Image["button_play_down"] = Utils :: getInstance().loadImage("img/button-play-down.png");
    Image["button_level_normal"] = Utils :: getInstance().loadImage("img/button-normal.png");
    Image["button_level_hover"] = Utils :: getInstance().loadImage("img/button-hover.png");
    Image["button_level_down"] = Utils :: getInstance().loadImage("img/button-down.png");

    Block[1] = Utils :: getInstance().loadImage("img/I.png");
    Block[2] = Utils :: getInstance().loadImage("img/Z.png");
    Block[3] = Utils :: getInstance().loadImage("img/J.png");
    Block[4] = Utils :: getInstance().loadImage("img/L.png");
    Block[5] = Utils :: getInstance().loadImage("img/O.png");
    Block[6] = Utils :: getInstance().loadImage("img/S.png");
    Block[7] = Utils :: getInstance().loadImage("img/T.png");

    SDL_Color color = {255, 255, 255, 255};
    Text["PLAY"] = Utils :: getInstance().loadText("PLAY", color);
    Text["Level 1"] = Utils :: getInstance().loadText("LEVEL 1", color);
    Text["Level 2"] = Utils :: getInstance().loadText("LEVEL 2", color);
    Text["Level 3"] = Utils :: getInstance().loadText("LEVEL 3", color);
}

void AssetManager::RenderAssetMenu(ButtonState playState, ButtonState levelState, int level) {
    SDL_Renderer* renderer = Utils::getInstance().getRenderer();
    SDL_RenderClear(renderer);

    // Vẽ nền và logo
    SDL_RenderCopy(renderer, Image["background"], NULL, nullptr);
    SDL_RenderCopy(renderer, Image["mainLogo"], NULL, &RectLayout::getInstance().getLogoRect());

    // Xác định key tương ứng với trạng thái của nút "Play"
    std::string playKey = "button_play_";
    switch (playState) {
        case HOVER: playKey += "hover"; break;
        case DOWN:  playKey += "down"; break;
        default:    playKey += "normal"; break;
    }

    // Xác định key tương ứng với trạng thái của nút "Level"
    std::string levelKey = "button_level_";
    switch (levelState) {
        case HOVER: levelKey += "hover"; break;
        case DOWN:  levelKey += "down"; break;
        default:    levelKey += "normal"; break;
    }

    std :: string levelText = "Level ";
    switch (level)
    {
        case 1: levelText += "1"; break;
        case 2: levelText += "2"; break;
        default: levelText += "3"; break;
    }

    // Vẽ các nút
    SDL_RenderCopy(renderer, Image[playKey], NULL, &RectLayout::getInstance().getButtonPlayRect());
    SDL_RenderCopy(renderer, Image[levelKey], NULL, &RectLayout::getInstance().getButtonLeverRect());
    SDL_RenderCopy(renderer, Text["PLAY"], NULL, &RectLayout :: getInstance().getTextPlayRect());
    SDL_RenderCopy(renderer, Text[levelText], NULL, &RectLayout :: getInstance().getTextLevelRect());
    SDL_RenderPresent(renderer);
}


void AssetManager :: RenderAssetGame() {
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Image["background"], NULL, NULL);
    SDL_RenderCopy(Utils :: getInstance().getRenderer(), Image["matrix"], NULL, &RectLayout :: getInstance().getMatrixRect());
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
