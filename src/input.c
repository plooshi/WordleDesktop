#include "input.h"
#include "guess.h"
#include "ui/color.h"
#include "ui/labels.h"
#include "ui/rows.h"
#include "ui/box.h"
#include "score.h"


bool dontAcceptKeys = false;
int guessCount = 0;
bool rl = false;


void upGuessCount() {
    guessCount = guessCount + 1;
}

bool isOutOfGuesses() {
    if (guessCount >= 6) {
        return true;
    } else {
        return false;
    }
}

void doRedLabels() {
    if (!guessValid(guess) && rl == false) {
        redLabels();
        rl = true;
    }
}

gboolean handleKeys(GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
    gchar* key = event->string;
    guint keyval = event->keyval;
    if (dontAcceptKeys == true) {
        resetGuess();
        return true;
    };
    if (keyval == GDK_KEY_Return) {
        if (strlen(guess) < 5) {
            return false;
        } else if (strlen(guess) == 5 && !guessValid(guess)) {
            doRedLabels();
            return false;
        }
        upGuessCount();
        
        
        colorLabels();
        colorOsk();
        if (checkWin() || isOutOfGuesses()) return dontAcceptKeys = true;
        resetGuess();
        updateGuessArray();
        guessRow();
        refreshLabels();

        return true;
    }
    if (keyval == GDK_KEY_BackSpace) {
        if (strlen(guess) == 0) return false;
        guess[strlen(guess)-1] = '\0';
        updateGuessArray();
        refreshLabels();
        rl = false;
        return true;
    }
    if (strlen(guess) >= 5) {
        doRedLabels();
        return false;
    }
    if (!((char)key[0] >= 'a' && (char)key[0] <= 'z') || ((char)key[0] >= 'A' && (char)key[0] <= 'Z')) return false;
    #ifdef _MSC_VER
        strcat_s(guess, 6, (char*)key);
    #else
        strncat(guess, (char*)key, sizeof(guess) - strlen(guess) - 1);
    #endif
    updateGuessArray();
    refreshLabels();
    if (strlen(guess) >= 5) {
        doRedLabels();
    }
    return true;
}