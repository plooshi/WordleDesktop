#ifndef __APPLE__
#include <gtk-3.0/gdk/gdkkeysyms.h>
#else
#include <gdk/gdkkeysyms.h>
#endif
#ifndef __APPLE__
#include <gtk-3.0/gtk/gtk.h>
#else
#include <gtk/gtk.h>
#endif
#pragma once
#ifndef INPUT_INCL
#define INPUT_INCL 1
gboolean handleKeys(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
#endif