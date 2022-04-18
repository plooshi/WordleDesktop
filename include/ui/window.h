#ifndef __APPLE__
#include <gtk-3.0/gtk/gtk.h>
#else
#include <gtk/gtk.h>
#endif
#pragma once
#ifndef UI_WINDOW_INCL
#define UI_WINDOW_INCL 1
void mainWindow(GtkApplication* app, gpointer user_data);
extern GtkWidget *window;
#endif