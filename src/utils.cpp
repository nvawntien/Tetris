#include "utils.h"

Utils& Utils :: getInstance() {
    static Utils instance;
    return instance;
}

SDL_Window* Utils :: getWindow() {
    return window;
}

SDL_Renderer* Utils :: getRenderer() {
    return renderer;
}

Mix_Music* Utils :: getMusic() {
    return backgroundMusic;
}

void Utils :: initSDL() {
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    font = TTF_OpenFont(FONTS_PATH"MuseoSans500.otf", 33);
    font1 = TTF_OpenFont(FONTS_PATH"MuseoSans500.otf", 24);
    backgroundMusic = Mix_LoadMUS(AUDIO_BACKGROUND_PATH);
}

void Utils :: quitSDL() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_FreeMusic(backgroundMusic);
    
    TTF_CloseFont(font);
    TTF_CloseFont(font1);
    font = nullptr;
    font1 = nullptr;

    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
}

void Utils :: loadHighScores(const std :: string& filename, std::vector <int>& highScores) {
    std::ifstream file(filename);
    highScores.clear();
    if (file.is_open()) {
        int score;
        while (file >> score) {
            highScores.push_back(score);
        }
        file.close();
    }
}

// Lưu điểm cao nhất lại

void Utils :: saveHighScores(const std :: string& filename, std::vector <int>& highScores) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int score : highScores) {
            file << score << "\n";
        }
        file.close();
    }
}

// cập nhật điểm cao nhất

void Utils ::  updateHighScores(int newScore, std::vector<int>& highScores) {
    highScores.push_back(newScore);
    std::sort(highScores.rbegin(), highScores.rend()); // Sắp xếp giảm dần
    if (highScores.size() > 5) {
        highScores.resize(5); // Giữ đúng 5 phần tử
    }
}

SDL_Texture* Utils::loadImage(const std :: string &path) {
    SDL_Texture *newTexture = nullptr;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);   
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

SDL_Texture* Utils::loadText(const std::string& text, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* Utils :: loadStats(const std::string& text, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Blended(font1, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(getRenderer(), surface);
    SDL_FreeSurface(surface);
    return texture;
}

Mix_Chunk* Utils::loadSoundEffect(const std::string& path) {
    Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
    if (!chunk) {
        std::cerr << "Failed to load sound effect: " << path 
                  << "\nError: " << Mix_GetError() << std::endl;
    }
    return chunk;
}



