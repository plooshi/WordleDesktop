#include "event.h"
#include "common.h"


gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    gchar* key = event->string;
    guint keyval = event->keyval;
    if (won == true) return true;
    if (keyval == GDK_KEY_Return) {
        char *cwGuess = guess;
        //if (guesses >= 6) return false;
        if (strlen(guess) < 5) return false;
        //if (!guessValid(guess)) return false;
        guesses++;
        
        
        colorLabels();
        checkWin();
        //refreshLabels();
        resetGuess();
        updateGuessArray();
        createRow();
        refreshLabels();

        return true;
    }
    if (keyval == GDK_KEY_BackSpace) {
        char* ng = guess;
        ng[strlen(guess)-1] = '\0';
        ng = "";
        updateGuessArray();
        refreshLabels();
        return true;
    }
    if (strlen(guess) >= 5) return false;
    //if (guesses >= 6) return false;
    #ifdef _MSC_VER
        strcat_s(guess, 6, (char*)key);
    #else
        strcat(guess, (char*)key);
    #endif
    updateGuessArray();
    refreshLabels();
    //colorLabels();
    return true;
}