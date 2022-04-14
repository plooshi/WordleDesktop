#include "event.h"
#include "gui.h"
#include "common.h"

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
   gchar* key = event->string;
   #ifdef _MSC_VER
   strcat_s(guess, 6, (char*)key);
   #else
   strcat(guess, (char*)key);
   #endif
   return true;
}