#include "event.h"

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
   gchar* key = event->string;
   strcat_s(guess, 6, (char*)key);
   return true;
}