#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include "utils.h"
#include "RectLayout.h"

enum TextureType {
    BACKGROUND = 1,
    LOGO = 2,
    MATRIX = 3,
    MENU_FRAME = 5,
    MENU_GAMEOVER = 7,
    ICON_HOME = 9,
    ICON_REPLAY = 11,
    HIGH_SCORE = 13,
    GREEN  = 1 << 2,
    BLACK  = 1 << 3,
    PAUSE = 1 << 4,
    HOME = 1 << 5,
    REPLAY = 1 << 6,
    TARGET = 1 << 7,
    L1 = 1,
    L2 = 2,
    L3 = 3,
    RESUME = 4,
    QUIT = 5,
    PLAY = 6,
    SCORE = 7,
    LINES = 8
};

enum AudioType {
    ROTATE = 1,
    MOVE = 2,
    LINE_CLEAR = 3,
    HOLD = 4,
    HARD_DROP = 5,
    LOCK = 6,
    GAMEOVER = 7
};

enum BlockType {
    I = 1,
    Z = 2,
    J = 3,
    L = 4,
    O = 5,
    S = 6,
    T = 7
};


class AssetManager {
    public:
        static AssetManager& getInstance();
        void loadAssets();
        void RenderAssetMenu(ButtonState playState, ButtonState leverState, int level,std::vector <int>& highScores);
        void RenderAssetGame(int score, int level, int lines, ButtonState pauseState);
        void RenderAssetPause(ButtonState resumeState, ButtonState quitState);
        void RenderAssetGameOver(ButtonState homeState, ButtonState replayState, std::vector <int>& highScore);
        void RenderNextBlock(int color, int i);
        void RenderHoldBlock(int color);
        void RenderNormalBlock(int x, int y, int color);
        void RenderGhostBlock(int x, int y, int color);
        void RenderLockedBlock(int x, int y, int color);
        void OpenBackgroundMusic();
        void OpenSoundEffect(AudioType sound);
        void clean();
    private:
        AssetManager() = default;  // Constructor private
        ~AssetManager() = default; // Destructor privatw
        AssetManager(const AssetManager&) = delete;
        AssetManager& operator=(const AssetManager&) = delete;
        std :: unordered_map <int, SDL_Texture*> Image;
        std :: unordered_map <int, SDL_Texture*> Text;
        std :: unordered_map <int, SDL_Texture*> Normal_Block, Ghost_Block, Locked_Block, Whole_Block;
        std :: unordered_map <int, SDL_Texture*> High_Score;
        std :: unordered_map <int, Mix_Chunk*> Audio;
        int prevScore = -1; 
        int prelineCleared = -1; 
};

#endif

