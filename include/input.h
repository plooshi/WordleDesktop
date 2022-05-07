#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#pragma once
#ifndef INPUT_INCL
#define INPUT_INCL 1
gboolean handleKeys(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
#endif