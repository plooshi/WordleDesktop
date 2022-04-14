#include "event.h"
#include "common.h"


gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
   gchar* key = event->string;
   guint keyval = event->keyval;
   if (keyval == GDK_KEY_Return) {
      if (guesses >= 6) return false;
      if (strlen(guess) < 5) return false;
      if (!guessValid(guess)) return false;
      guesses += 1;
      //colorizeScore(score(guess));
      guess = "";
      updateGuessArray();
      refreshLabels();

      return true;
   }
   if (keyval == GDK_KEY_BackSpace) {
      guess = "";
      updateGuessArray();
      refreshLabels();
   }
   #ifdef _MSC_VER
   strcat_s(guess, 6, (char*)key);
   #else
   strcat(guess, (char*)key);
   #endif
   updateGuessArray();
   refreshLabels();
   return true;
}