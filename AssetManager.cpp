#include "AssetManager.h"

AssetManager& AssetManager :: getInstance() {
    static AssetManager instance;
    return instance;
}

void AssetManager :: InitButtonRect() {
    mainLogoRect = {(SCREEN_WIDTH - 240) / 2, (SCREEN_HEIGHT - GRID_HEIGHT * BLOCK_SIZE) / 2 + BLOCK_SIZE / 5, 240, 160};
    buttonPlayRect = {(SCREEN_WIDTH - 200) / 2, mainLogoRect.y + 160 + BLOCK_SIZE / 2, 200, 60};
    buttonLeverRect = {buttonPlayRect.x, buttonPlayRect.y + 60 + BLOCK_SIZE / 2, 200, 60};
}

void AssetManager :: loadAssets() {
    Image["background"] = Util :: getInstance().loadImage("img/background.png");
    Image["mainLogo"] = Util :: getInstance().loadImage("img/main-logo.png");
    Image["button_play_normal"] = Util :: getInstance().loadImage("img/button-play-normal.png");
    Image["button_play_hover"] = Util :: getInstance().loadImage("img/button-play-hover.png");
    Image["button_play_down"] = Util :: getInstance().loadImage("img/button-play-down.png");
    Image["button_normal"] = Util :: getInstance().loadImage("img/button-normal.png");
    Image["button_hover"] = Util :: getInstance().loadImage("img/button-hover.png");
    Image["button_down"] = Util :: getInstance().loadImage("img/button-down.png");

    SDL_Color color = {255, 255, 255, 255};
    Text["PLAY"] = Util :: getInstance().loadText("PLAY", color);
    Text["Lever1"] = Util :: getInstance().loadText("LEVER 1", color);
}

void AssetManager :: RenderAssetMenu() {
    SDL_RenderClear(Util :: getInstance().getRenderer());

    SDL_RenderCopy(Util :: getInstance().getRenderer(), Image["background"], NULL, NULL);
    SDL_RenderCopy(Util :: getInstance().getRenderer(), Image["mainLogo"], NULL, &mainLogoRect);
    SDL_RenderCopy(Util :: getInstance().getRenderer(), Image["button_play_normal"], NULL, &buttonPlayRect);
    SDL_RenderCopy(Util :: getInstance().getRenderer(), Image["button_normal"], NULL, &buttonLeverRect);

    
    // Lấy kích thước của chữ
    int textW, textH;
    TTF_SizeText(Util :: getInstance().getFont(), "PLAY", &textW, &textH);
    SDL_Rect playTextRect = {buttonPlayRect.x + (buttonPlayRect.w - textW) / 2, buttonPlayRect.y + (buttonPlayRect.h - textH) / 2, textW, textH};
    TTF_SizeText(Util :: getInstance().getFont(), "LEVEL 1", &textW, &textH);
    SDL_Rect levelTextRect = {buttonLeverRect.x + (buttonLeverRect.w - textW) / 2, buttonLeverRect.y + (buttonLeverRect.h - textH) / 2, textW, textH};

    SDL_RenderCopy(Util::getInstance().getRenderer(), Text["PLAY"], NULL, &playTextRect);
    SDL_RenderCopy(Util::getInstance().getRenderer(), Text["Lever1"], NULL, &levelTextRect);
    
    SDL_RenderPresent(Util :: getInstance().getRenderer());  
}

void AssetManager ::  clean() {
    for (auto &pair : Image) {
        SDL_DestroyTexture(pair.second);
    }

    for (auto &pair : Text) {
        SDL_DestroyTexture(pair.second);
    }

    Image.clear();
    Text.clear();
}
