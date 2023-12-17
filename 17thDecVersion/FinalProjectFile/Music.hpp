#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>


class BackgroundMusic{
private:
    Mix_Music* music;
    // pointer to what music we want

public:
    BackgroundMusic(const char* thefile);
    //cons

    ~BackgroundMusic();
    //des

    void play(int repetition);

    void pause();

    void resume();
    //fucntions to smoothen out audio

};