#ifndef RECTLAYOUT_H
#define RECTLAYOUT_H
#include "utils.h"

enum ButtonState {
    NORMAL = 1 << 7,
    HOVER = 1 << 8,
    DOWN = 1 << 9
};

class RectLayout {
    public:
        static RectLayout& getInstance(); // Singleton accessor
        void CreateRect();
        SDL_Rect& getBlockRect(int x, int y);
        
        SDL_Rect& getLogoRect();
        SDL_Rect& getMatrixRect();
        SDL_Rect& getMenuFrameRect();
        SDL_Rect& getMenuGameOverRect();
        SDL_Rect& getIconHomeRect();
        SDL_Rect& getIconReplayRect();
        SDL_Rect& getHighScoreRect();

        SDL_Rect& getButtonPlayRect();
        SDL_Rect& getButtonLevelRect();
        SDL_Rect& getButtonPauseRect();
        SDL_Rect& getButtonResumeRect();
        SDL_Rect& getButtonQuitRect();
        SDL_Rect& getButtonHomeRect();
        SDL_Rect& getButtonReplayRect();

        SDL_Rect& getPlayTextRect(SDL_Texture* texture);
        SDL_Rect& getLevelTextRect(SDL_Texture* texture);
        SDL_Rect& getResumeTextRect(SDL_Texture* texture);
        SDL_Rect& getQuitTextRect(SDL_Texture* texture);
      
        SDL_Rect& getScoreTextRect(SDL_Texture* texture);
        SDL_Rect& getLevelMiniTextRect(SDL_Texture* texture);
        SDL_Rect& getLinesTextRect(SDL_Texture* texture);
        SDL_Rect& getNextRect(SDL_Texture* texture, int i);
        SDL_Rect& getHoldRect(SDL_Texture* texture);
        SDL_Rect& getMenuHighScoreTextRect(SDL_Texture* texture, int i);
        SDL_Rect& getGameOverHighScoreTextRect(SDL_Texture* texture, int i);
    private:
        RectLayout() = default;
        ~RectLayout() = default;
        RectLayout(const RectLayout&) = delete;
        RectLayout& operator=(const RectLayout&) = delete;
        
        SDL_Rect gridRects[CELL_HEIGHT][CELL_WIDTH];
        SDL_Rect menu_HighScore[5], gameOver_HighScore[5];
        SDL_Rect queueRect[3];
        SDL_Rect holdRect;
        SDL_Rect mainLogoRect;
        SDL_Rect matrix;
        SDL_Rect menuFrameRect;
        SDL_Rect menuGameOverRect;
        SDL_Rect iconHomeRect;
        SDL_Rect iconReplayRect;
        SDL_Rect highScoreRect;
        
        SDL_Rect buttonPlayRect;
        SDL_Rect buttonLevelRect;
        SDL_Rect buttonResumeRect;
        SDL_Rect buttonQuitRect;
        SDL_Rect buttonPauseRect;
        SDL_Rect buttonHomeRect;
        SDL_Rect buttonReplayRect;

        SDL_Rect playTextRect;
        SDL_Rect levelTextRect;
        SDL_Rect resumeTextRect;
        SDL_Rect quitTextRect;
        SDL_Rect scoreTextRect;
        SDL_Rect levelMiniTextRect;
        SDL_Rect linesTextRect;
        SDL_Rect highScoreTextRect[5];
    
        SDL_Rect scoreRect;
        SDL_Rect levelRect;
        SDL_Rect linesRect; 
};  

#endif