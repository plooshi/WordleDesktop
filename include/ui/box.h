#ifndef __APPLE__
#include <gtk-3.0/gtk/gtk.h>
#else
#include <gtk/gtk.h>
#endif
#pragma once
#ifndef UI_BOX_INCL
#define UI_BOX_INCL 1
extern GtkListBox *list_box;
void boxInit();
#endif