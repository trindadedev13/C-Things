#ifndef CM_SOUND_H
#define CM_SOUND_H

#include <SDL2/SDL_mixer.h>

struct cm_sound {
  char* name;
  Mix_Music* music;
};

#define cm_sound(name) cm_sound_make(name);

struct cm_sound cm_sound_make(char* name);

int cm_sound_init();

int cm_sound_isplaying();

void cm_sound_delay(int ms);

void cm_sound_end(struct cm_sound* cms);

int cm_sound_play(struct cm_sound* cms);

#endif