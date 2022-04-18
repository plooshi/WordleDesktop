#include "input.h"
#include "guess.h"
#include "ui/color.h"
#include "ui/labels.h"
#include "ui/rows.h"
#include "ui/box.h"
#include "score.h"


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

gboolean handleKeys(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
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
        if (checkWin() || isOutOfGuesses()) return dontAcceptKeys = true;
        resetGuess();
        updateGuessArray();
        guessRow();
        refreshLabels();

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
    return true;
}