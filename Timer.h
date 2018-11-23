#pragma once

#include <SDL_timer.h>
#include <SDL_stdinc.h>
class Timer {
public:
    Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    Uint32 getTicks();

    bool isStarted();
    bool isPaused();
private:
    Uint32 tStartTicks;
    Uint32 tPausedTicks;

    bool tPaused;
    bool tStarted;
};

