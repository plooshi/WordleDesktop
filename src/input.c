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
        #ifndef _MSC_VER
        resetGuess();
        #endif
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
        ng
        #else
        guess
        #endif
        [strlen(guess)-1] = '\0';
        #ifdef _MSC_VER
        ng = "";
        #endif
        updateGuessArray();
        refreshLabels();
        return true;
    }
    if (strlen(guess) >= 5) return false;
    if (!((char)key[0] >= 'a' && (char)key[0] <= 'z') || ((char)key[0] >= 'A' && (char)key[0] <= 'Z')) return false;
    #ifdef _MSC_VER
        strcat_s(guess, 6, (char*)key);
    #else
        strncat(guess, (char*)key, sizeof(guess) - strlen(guess) - 1);
    #endif
    updateGuessArray();
    refreshLabels();
    return true;
}