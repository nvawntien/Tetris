#ifndef RECTLAYOUT_H
#define RECTLAYOUT_H
#include "utils.h"

enum ButtonState {
    NORMAL,
    HOVER,
    DOWN
};

class RectLayout {
    public:
        static RectLayout& getInstance(); // Singleton accessor
        void CreateRect();
        SDL_Rect& getBlockRect(int x, int y);
        SDL_Rect& getLogoRect();
        SDL_Rect& getButtonPlayRect();
        SDL_Rect& getButtonLeverRect();
        SDL_Rect& getMatrixRect();
        SDL_Rect& getTextPlayRect();
        SDL_Rect& getTextLevelRect();
    private:
        RectLayout() = default;
        ~RectLayout() = default;
        RectLayout(const RectLayout&) = delete;
        RectLayout& operator=(const RectLayout&) = delete;
        const int gridOffsetx = (SCREEN_WIDTH - GRID_WIDTH) / 2 + 6;
        const int gridOffsety = (SCREEN_HEIGHT - GRID_HEIGHT) / 2 + 7;
        SDL_Rect gridRects[CELL_HEIGHT][CELL_WIDTH];
        SDL_Rect mainLogoRect;
        SDL_Rect buttonPlayRect;
        SDL_Rect buttonLeverRect;
        SDL_Rect matrix;
        SDL_Rect textPlayRect;
        SDL_Rect textLevelRect;
};

#endif