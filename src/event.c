#include "event.h"
#include "common.h"


bool dontAcceptKeys = false;
int guesses = 0;


void upGuessCount() {
    guesses = guesses + 1;
}

bool isOutOfGuesses() {
    if (guesses >= 6) {
        return true;
    } else {
        return false;
    }
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    gchar* key = event->string;
    guint keyval = event->keyval;
    if (dontAcceptKeys == true) {
        guess = "";
        return true;
    };
    if (keyval == GDK_KEY_Return) {
        if (strlen(guess) < 5) return false;
        if (!guessValid(guess)) return false;
        upGuessCount();
        
        
        colorLabels();
        dontAcceptKeys = checkWin();
        //refreshLabels();
        resetGuess();
        updateGuessArray();
        createRow();
        refreshLabels();

        
        if (isOutOfGuesses() && dontAcceptKeys == false) dontAcceptKeys = true;

        return true;
    }
    if (keyval == GDK_KEY_BackSpace) {
        #ifdef _MSC_VER
        char* ng = guess;
        #else
        char ng[] = guess;
        #endif
        ng[strlen(guess)-1] = '\0';
        ng = "";
        updateGuessArray();
        refreshLabels();
        return true;
    }
    if (strlen(guess) >= 5) return false;
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