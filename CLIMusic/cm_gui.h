#ifndef CM_GUI_H
#define CM_GUI_H

#include <stdarg.h>
#include "cm_colors.h"

#define CM_GUI_FILL_CHAR "■"

struct cm_gui_vector2i {
  int x;
  int y;
};

#define cm_gui_vector2i(y, x) cm_gui_make_vector2i(y, x)

struct cm_gui_vector2i cm_gui_make_vector2i(int y, int x);

void cm_gui_draw_rect(cm_color_pair color, struct cm_gui_vector2i vec, int width, int height);

void cm_gui_draw_text(cm_color_pair color, struct cm_gui_vector2i vec, const char *fmt, ...);

#endif