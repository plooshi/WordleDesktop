#include "event.h"
#include "common.h"

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
   gchar* key = event->string;
   guint keyval = event->keyval;
   if (keyval == GDK_KEY_Return) {
      return true;
   }
   #ifdef _MSC_VER
   strcat_s(guess, 6, (char*)key);
   #else
   strcat(guess, (char*)key);
   #endif
   return true;
}