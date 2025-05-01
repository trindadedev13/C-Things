#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "cm_sound.h"

struct cm_sound cm_sound_make(char* name) {
  struct cm_sound s;
  s.name = name;
  return s;
}

int cm_sound_init() {
  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    return 1;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    return 1;
  }

  return 0;
}

int cm_sound_isplaying() {
  return Mix_PlayingMusic();
}

void cm_sound_delay(int ms) {
  SDL_Delay(ms);
}

void cm_sound_end(struct cm_sound* cms) {
  if (cms->music) {
    Mix_FreeMusic(cms->music);
  }
  Mix_CloseAudio();
  SDL_Quit();
}

int cm_sound_play(struct cm_sound* cms) {
  cms->music = Mix_LoadMUS(cms->name);
  if (!cms->music) {
    return 1;
  }

  if (Mix_PlayMusic(cms->music, 1) < 0) {
    return 1;
  }

  return 0;
}