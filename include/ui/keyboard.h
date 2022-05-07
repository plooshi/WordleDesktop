#include <gtk/gtk.h>
#pragma once
#ifndef UI_KEYBOARD_INCL
#define UI_KEYBOARD_INCL 1
extern GArray *keyboard;
extern GtkWidget *keyboardGrid;
void keyboardInit();
int getLeft(int i);
int getTop(int i);
#endif