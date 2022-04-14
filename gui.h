#pragma once
#ifndef GUI_INCL
#define GUI_INCL 1
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gdk/gdkkeysyms.h>

static void render(GtkApplication *app, gpointer data);

int gtkMain();
void refreshLabels();
extern GtkWidget *letter1, *letter2, *letter3, *letter4, *letter5;
#endif