#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include "utils.h"
#include "RectLayout.h"

enum TextureType {
    BACKGROUND = 1 << 0,
    LOGO = 1 << 1,
    MATRIX = 1 << 2,
    GREEN  = 1 << 3,
    BLACK  = 1 << 4,
    PAUSE = 1 << 5,
    SCORE = 1 << 6,
    LINES = 1 << 7,
    TARGET = 1 << 8,
    MENU_FRAME = 1 << 9,
    L1 = 1,
    L2 = 2,
    L3 = 3,
    RESUME = 4,
    QUIT = 5,
    PLAY = 6
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
        void RenderAssetMenu(ButtonState playState, ButtonState leverState, int level);
        void RenderAssetGame(int score, int level, int lines, ButtonState pauseState);
        void RenderAssetPause(ButtonState resumeState, ButtonState quitState);
        void RenderNextBlock(int color, int i);
        void RenderHoldBlock(int color);
        void RenderNormalBlock(int x, int y, int color);
        void RenderGhostBlock(int x, int y, int color);
        void RenderLockedBlock(int x, int y, int color);
        SDL_Rect getRect();
        void clean();
    private:
        AssetManager() = default;  // Constructor private
        ~AssetManager() = default; // Destructor privatw
        AssetManager(const AssetManager&) = delete;
        AssetManager& operator=(const AssetManager&) = delete;
        std :: unordered_map <int, SDL_Texture*> Image;
        std :: unordered_map <int, SDL_Texture*> Text;
        std :: unordered_map <int, SDL_Texture*> Normal_Block, Ghost_Block, Locked_Block, Whole_Block;
        int prevScore = -1; 
        int prelineCleared = -1;
};

#endif

