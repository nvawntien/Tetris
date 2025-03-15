#include "utils.h"
#include "game.h"

int main(int argc, char* argv[]) {
    Util *util = new Util;
    Game *player = new Game;

    if (player -> initGame()) {
        while (player -> menu()) {
            while (player -> isRunning()) {
                player -> Event();
            }
        }
    }
    
    util -> quitSDL(util -> window, util -> renderer);
    return 0;
}
