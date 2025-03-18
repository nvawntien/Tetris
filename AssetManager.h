#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include "utils.h"

class AssetManager {
    public:
        static AssetManager& getInstance();
        void loadAssets();
        void RenderAssetMenu();
        void InitButtonRect();
        SDL_Rect getRect();
        void clean();
    private:
        AssetManager() = default;  // Constructor private
        ~AssetManager() = default; // Destructor privatw
        AssetManager(const AssetManager&) = delete;
        AssetManager& operator=(const AssetManager&) = delete;
        
        SDL_Rect mainLogoRect;
        SDL_Rect buttonPlayRect;
        SDL_Rect buttonLeverRect;
        std :: unordered_map <std :: string, SDL_Texture*> Image, Text;
};

#endif

