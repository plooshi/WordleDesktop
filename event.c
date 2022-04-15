#include "event.h"
#include "common.h"

void removeChar(char *str, char c) {
    char *string1 = str;
    char *string2 = str;
    for(; *string2 != 0; string1++) {
        if (*string1 == c && *string1) continue;
        *string2 = *string1;
        string2++;
        if (!*string1) return;
    }
}


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
        ccharg = 0;
        updateGuessArray();
        refreshLabels();

        return true;
   }
   if (keyval == GDK_KEY_BackSpace) {
        char *ng = "";
        for (int i = 0; i < ccharg-1; i++) { 
            if (i == ccharg-1) {

            } else {
                #ifdef _MSC_VER
                    strcat_s(ng, 6, (char*)guessa[i]);
                #else
                    strcat(ng, (char*)guessa[i]);
                #endif
            }
        }
        guess = ng;
        ng = "";
        //guess[ccharg] = "";
        ccharg--;
        updateGuessArray();
        refreshLabels();
        return true;
   }
   char *ng = guess;
    #ifdef _MSC_VER
        strcat_s(ng, 5, (char*)key);
    #else
        strcat(ng, (char*)key);
    #endif
    guess = ng;
    ccharg++;
    updateGuessArray();
    refreshLabels();
    return true;
}