//
// Created by Chris on 9/9/2018.
//

#ifndef INC_2DENGINE_TIMER_H
#define INC_2DENGINE_TIMER_H


#include <SDL2/SDL_stdinc.h>

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


#endif //INC_2DENGINE_TIMER_H
