#ifndef __APPLE__
#include <gtk-3.0/gtk/gtk.h>
#else
#include <gtk/gtk.h>
#endif
#pragma once
#ifndef UI_KEYBOARD_INCL
#define UI_KEYBOARD_INCL 1
extern GArray *keyboard;
extern GtkWidget *keyboardGrid;
void keyboardInit();
int getLeft(int i);
int getTop(int i);
#endif