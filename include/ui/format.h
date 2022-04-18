#ifndef __APPLE__
#include <gtk-3.0/gtk/gtk.h>
#else
#include <gtk/gtk.h>
#endif
#pragma once
#ifndef UI_FORMAT_INCL
#define UI_FORMAT_INCL 1
void formatLabel(GtkLabel *label);
void formatWordleBanner(GtkLabel *label);
#endif