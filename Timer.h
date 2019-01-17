#pragma once

#include <SDL_timer.h>
#include <SDL_stdinc.h>
#include <ctime>
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

	int* getRealTime();
private:
    Uint32 tStartTicks;
    Uint32 tPausedTicks;

    bool tPaused;
    bool tStarted;
};

