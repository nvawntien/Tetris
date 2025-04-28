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
        SDL_Rect& getMatrixRect();
        SDL_Rect& getMenuFrameRect();

        SDL_Rect& getButtonPlayRect();
        SDL_Rect& getButtonLevelRect();
        SDL_Rect& getButtonPauseRect();
        SDL_Rect& getButtonResumeRect();
        SDL_Rect& getButtonQuitRect();

        SDL_Rect& getPlayTextRect(SDL_Texture* texture);
        SDL_Rect& getLevelTextRect(SDL_Texture* texture);
        SDL_Rect& getResumeTextRect(SDL_Texture* texture);
        SDL_Rect& getQuitTextRect(SDL_Texture* texture);
      
        SDL_Rect& getScoreTextRect(SDL_Texture* texture);
        SDL_Rect& getLevelMiniTextRect(SDL_Texture* texture);
        SDL_Rect& getLinesTextRect(SDL_Texture* texture);
        SDL_Rect& getNextRect(SDL_Texture* texture, int i);
        SDL_Rect& getHoldRect(SDL_Texture* texture);
       
      
    private:
        RectLayout() = default;
        ~RectLayout() = default;
        RectLayout(const RectLayout&) = delete;
        RectLayout& operator=(const RectLayout&) = delete;
        
        SDL_Rect gridRects[CELL_HEIGHT][CELL_WIDTH];
        SDL_Rect queueRect[3];
        SDL_Rect holdRect;
        SDL_Rect mainLogoRect;
        SDL_Rect matrix;
        SDL_Rect menuFrameRect;

        SDL_Rect buttonPlayRect;
        SDL_Rect buttonLevelRect;
        SDL_Rect buttonResumeRect;
        SDL_Rect buttonQuitRect;
        SDL_Rect buttonPauseRect;

        SDL_Rect playTextRect;
        SDL_Rect levelTextRect;
        SDL_Rect resumeTextRect;
        SDL_Rect quitTextRect;
        SDL_Rect scoreTextRect;
        SDL_Rect levelMiniTextRect;
        SDL_Rect linesTextRect;
        
        
        SDL_Rect scoreRect;
        SDL_Rect levelRect;
        SDL_Rect linesRect; 
};  

#endif