#ifndef RECTLAYOUT_H
#define RECTLAYOUT_H
#include "utils.h"

enum ButtonState {
    NORMAL = 1 << 6,
    HOVER = 1 << 7,
    DOWN = 1 << 8
};

class RectLayout {
    public:
        static RectLayout& getInstance(); // Singleton accessor
        void CreateRect();
        SDL_Rect& getBlockRect(int x, int y);
        SDL_Rect& getLogoRect();
        SDL_Rect& getButtonPlayRect();
        SDL_Rect& getButtonLevelRect();
        SDL_Rect& getMatrixRect();
        SDL_Rect& getTextPlayRect(SDL_Texture* texture);
        SDL_Rect& getTextLevelRect(SDL_Texture* texture);
        SDL_Rect& getButtonPauseRect();
        SDL_Rect& getScoreRect(SDL_Texture* texture);
        SDL_Rect& getLevelRect(SDL_Texture* texture);
        SDL_Rect& getLinesRect(SDL_Texture* texture);
    private:
        RectLayout() = default;
        ~RectLayout() = default;
        RectLayout(const RectLayout&) = delete;
        RectLayout& operator=(const RectLayout&) = delete;
        SDL_Rect gridRects[CELL_HEIGHT][CELL_WIDTH];
        SDL_Rect mainLogoRect;
        SDL_Rect buttonPlayRect;
        SDL_Rect buttonLevelRect;
        SDL_Rect matrix;
        SDL_Rect textPlayRect;
        SDL_Rect textLevelRect;
        SDL_Rect buttonPauseRect;
        SDL_Rect scoreRect;
        SDL_Rect levelRect;
        SDL_Rect linesRect;
        SDL_Rect scoreTextRect;
        SDL_Rect levelTextRect;
        SDL_Rect linesTextRect;
};  

#endif