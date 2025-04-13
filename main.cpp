#include "utils.h"
#include "game.h"
#include "AssetManager.h"

int main(int argc, char* argv[]) {
    Game *player = new Game;

    while (player -> isRunning()) {
        switch (player -> gameState) {
            case MENU:
                 while (player -> Menu());
                break;
            case PLAYING:
                while (player -> GamePlay());
                break;
            case PAUSE:
                while (player -> GamePause());
                break;
            case GAME_OVER:
                while (player -> GameOver());
                break;
        }
    }
    
    Utils :: getInstance().quitSDL();
    AssetManager :: getInstance().clean();
    delete player;
    return 0;
}
