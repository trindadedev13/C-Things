#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "cm_colors.h"
#include "cm_file.h"
#include "cm_gui.h"

#define CM_MUSIC_INITIAL_CAPACITY 1

struct cm_vector {
  int x;
  int y;
};

struct cm_cursor {
  int x;
  int y;
};

struct cm_music {
  char* name;
  struct cm_vector position;
};

struct cm_screen {
  int xMax;
  int yMax;
  struct cm_cursor* cursor;
  struct cm_music* musics;
  int musics_amount;
  int musics_capacity;
};

struct cm_state {
  struct cm_screen* screen;
};

static void cm_state_close(struct cm_state cms) {
  free(cms.screen->cursor);
  free(cms.screen->musics);
  free(cms.screen);
}

int main() {
  struct cm_state cmstate;

  cmstate.screen = malloc(sizeof(struct cm_screen));
  if (!cmstate.screen) {
    perror("Failed to allocate memory for cmstate.screen");
  }

  cmstate.screen->musics_amount = 0;
  cmstate.screen->musics_capacity = CM_MUSIC_INITIAL_CAPACITY;

  cmstate.screen->cursor = malloc(sizeof(struct cm_cursor));
  if (!cmstate.screen->cursor) {
    perror("Failed to allocate memory for cmstate.screen->cursor");
  }

  cmstate.screen->musics = malloc(sizeof(struct cm_music) * CM_MUSIC_INITIAL_CAPACITY);
  if (!cmstate.screen->musics) {
    perror("Failed to allocate memory for cmstate.screen->musics");
  }

  initscr();                                                 // init ncurses
  noecho();                                                  // disable input
  cbreak();                                                  // send all char automatically without ENTER
  keypad(stdscr, TRUE);                                      // allow especial chars
  cm_colors_init(CM_COLOR_BACKGROUND_ID);                    // init colors and background color
  cm_colors_set_background_color(CM_COLOR_BACKGROUND_PAIR);  // defines background color
  cm_colors_enable_color(CM_COLOR_PRIMARY_PAIR);             // enable primary color for all
  curs_set(2);                                               // sets cursor visiblity to visible

  // gets terminal scr maxX & maxY to variables
  getmaxyx(stdscr, cmstate.screen->yMax, cmstate.screen->xMax);
  // cmstate.screen->yMax = cmstate.screen->yMax - 1;
  // cmstate.screen->yMax = cmstate.screen->xMax - 1;

  struct cm_file_list_dir_data* tld = cm_file_list_dir("cmmusics/");

  clear();
  cm_gui_draw_rect(
      CM_COLOR_PRIMARY_PAIR,
      cm_gui_vector2i(5, 10),
      20,
      6);
      
  cm_gui_draw_text(
      CM_COLOR_PRIMARY_PAIR,
      cm_gui_vector2i(cmstate.screen->yMax - 1, 0),
      "Press 'q' to quit.");
  if (tld && tld->len > 0) {
    int max_items = cmstate.screen->yMax - 2;
    for (int i = 0; i < tld->len && i < max_items; i++) {
      char* name = tld->dirs[i].name;
      int y = cmstate.screen->yMax / 2 + i;
      int x = cmstate.screen->xMax / 2 - 8;
      if (cmstate.screen->musics_amount >= cmstate.screen->musics_capacity) {
        cmstate.screen->musics_capacity = cmstate.screen->musics_amount + 1;
        cmstate.screen->musics = realloc(cmstate.screen->musics, sizeof(struct cm_music) * cmstate.screen->musics_capacity);
      }
      struct cm_music music;
      music.name = name;
      music.position.x = x;
      music.position.y = y;
      cmstate.screen->musics[cmstate.screen->musics_amount++] = music;
      cm_gui_draw_text(
          CM_COLOR_PRIMARY_PAIR,
          cm_gui_vector2i(y, x),
          "%s",
          name);
    }
    move(cmstate.screen->musics[0].position.y, cmstate.screen->musics[0].position.x);
  } else {
    mvprintw(cmstate.screen->yMax / 2, cmstate.screen->xMax / 2 - 5, "No files found");
    move(0, 0);  // move cursor to x:0 y:0
  }
  refresh();


  // handle chars
  // when 'q' finish problem
  int ch;
  while ((ch = getch()) != 'q') {
    // get current cursor position
    getyx(stdscr, cmstate.screen->cursor->y, cmstate.screen->cursor->x);

    if (ch == 'w' || ch == KEY_UP) {
      if (cmstate.screen->cursor->y != 0 && !(cmstate.screen->cursor->y <= cmstate.screen->musics[0].position.y)) {
        move(--cmstate.screen->cursor->y, cmstate.screen->cursor->x);
      }
    } else if (ch == 's' || ch == KEY_DOWN) {
      if (cmstate.screen->cursor->y != cmstate.screen->yMax && !(cmstate.screen->cursor->y >= cmstate.screen->musics[cmstate.screen->musics_amount - 1].position.y)) {
        move(++cmstate.screen->cursor->y, cmstate.screen->cursor->x);
      }
    }
  }

  // disable color
  cm_colors_disable_color(CM_COLOR_PRIMARY_PAIR);

  endwin(); // finish ncurses
  cm_file_list_dir_close(tld);
  cm_state_close(cmstate);
  return 0;
}