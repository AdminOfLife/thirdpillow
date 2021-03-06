//
// Created by jwpilly on 1/10/2016.
//

#include "timekeeper.h"

timekeeper::timekeeper() {
    start_ticks = 0;
    pause_ticks = 0;

    paused = false;
    started = false;
}

void timekeeper::start() {
    started = true;
    paused = false;
    start_ticks = SDL_GetTicks();
    pause_ticks = 0;
}

void timekeeper::stop() {
    started = false;
    paused = false;
    start_ticks = 0;
    pause_ticks = 0;
}

void timekeeper::pause() {
    if (started && !paused) {
        paused = true;
        pause_ticks = SDL_GetTicks() - start_ticks;
        start_ticks = 0;
    }
}

void timekeeper::unpause() {
    if (started && paused) {
        paused = false;
        start_ticks = SDL_GetTicks() - pause_ticks;
        pause_ticks = 0;
    }
}

long timekeeper::get_ticks() {
    if (started) {
        if (paused) {
            return pause_ticks;
        } else {
            return SDL_GetTicks() - start_ticks;
        }
    }
    return 0;
}

bool timekeeper::is_started() {
    return started;
}

bool timekeeper::is_paused() {
    return paused;
}

timekeeper::~timekeeper() {

}
