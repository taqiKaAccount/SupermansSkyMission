#pragma once

#include "Music.hpp"

BackgroundMusic::BackgroundMusic(const char* thefile) {
    //error checking messages
    //and then the file is loaded 
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }

    music = Mix_LoadMUS(thefile);
    if (music == nullptr) {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

BackgroundMusic::~BackgroundMusic() {
        Mix_FreeMusic(music);
        Mix_CloseAudio();
        SDL_Quit();
    }

void BackgroundMusic::play(int repetition) {
    Mix_PlayMusic(music, repetition); // -1 plays music infinitely
                            // if set to 2, it will play the bgm twice and then stop
                            //useful for small sound effects
}

void BackgroundMusic::pause() {
    if (Mix_PlayingMusic() != 0) {
        Mix_PauseMusic();
    }
}

void BackgroundMusic::resume() {
    if (Mix_PausedMusic() != 0) {
        Mix_ResumeMusic();
    }
}
