#include "event.h"
#include "common.h"


gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
   gchar* key = event->string;
   guint keyval = event->keyval;
    if (keyval == GDK_KEY_Return) {
        //if (guesses >= 6) return false;
        if (strlen(guess) < 5) return false;
        //if (!guessValid(guess)) return false;
        //guesses++;
        //colorizeScore(score(guess));
        
        
        refreshLabels();
        colorLabels();
        guess = "     ";
        updateGuessArray();
        guess = "";
        createRow();

        return true;
    }
    if (keyval == GDK_KEY_BackSpace) {
        char* ng = guess;
        ng[strlen(guess)-1] = '\0';
        ng = guess;
        updateGuessArray();
        refreshLabels();
        return true;
    }
    char *ng = guess;
    if (strlen(guess) >= 5) return false;
    //if (guesses >= 6) return false;
    #ifdef _MSC_VER
        strcat_s(ng, 6, (char*)key);
    #else
        strcat(ng, (char*)key);
    #endif
    guess = ng;
    updateGuessArray();
    refreshLabels();
    //colorLabels();
    return true;
}