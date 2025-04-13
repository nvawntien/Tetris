#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include "utils.h"
#include "RectLayout.h"

class AssetManager {
    public:
        static AssetManager& getInstance();
        void loadAssets();
        void RenderAssetMenu(ButtonState playState, ButtonState leverState, int level);
        void RenderAssetGame();
        void RenderBlock(int i, int j, int color);
        SDL_Rect getRect();
        void clean();
    private:
        AssetManager() = default;  // Constructor private
        ~AssetManager() = default; // Destructor privatw
        AssetManager(const AssetManager&) = delete;
        AssetManager& operator=(const AssetManager&) = delete;
        std :: unordered_map <std :: string, SDL_Texture*> Image, Text;
        std :: unordered_map <int, SDL_Texture*> Block; 
};

#endif

