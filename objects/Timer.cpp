#include <SDL2/SDL_timer.h>
#include "Timer.h"

Timer::Timer() {
    tStartTicks = 0;
    tPausedTicks = 0;
    tPaused = false;
    tStarted = false;
}

void Timer::start() {
    tStarted = true;
    tPaused = false;
    tStartTicks = SDL_GetTicks();
    tPausedTicks = 0;
}

void Timer::stop() {
    tStarted = false;
    tPaused = true;
    tStartTicks = 0;
    tPausedTicks = 0;
}

void Timer::pause() {
    if (tStarted && !tPaused) {
        tPaused = true;
        // store time when timer was paused
        tPausedTicks = SDL_GetTicks() - tStartTicks;
        tStartTicks = 0;
    }
}

void Timer::unpause() {
    if (tStarted && tPaused) {
        tPaused = false;
        tStartTicks = SDL_GetTicks() - tPausedTicks;
        tPausedTicks = 0;
    }
}

Uint32 Timer::getTicks() {
    Uint32 time = 0; // represents the actual timer time

    if (tStarted) {
        if (tPaused) {
            time = tPausedTicks; // return number of ticks when timer was paused
        }
        else {
            time = SDL_GetTicks()-tStartTicks; // return current time minus when timer was started
        }
    }
    return time;
}

bool Timer::isStarted() {return tStarted;}
bool Timer::isPaused() {return tPaused;}