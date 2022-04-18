#include <gtk-3.0/gdk/gdkkeysyms.h>
#include <gtk-3.0/gtk/gtk.h>
#pragma once
#ifndef INPUT_INCL
#define INPUT_INCL 1
gboolean handleKeys(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
#endif