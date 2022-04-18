#include "ui/color.h"
#include "guess.h"
#include "score.h"
#include "ui/labels.h"

void colorizeLabel(int val, int pos, GtkWidget *label) {
    char *format;
    gchar *markup;
    const gchar *text = gtk_label_get_text(GTK_LABEL(label));
    if (val == 2) {
        format = "<span background=\"#76ff03\" foreground=\"#000000\"> %s </span>";
    }
    else if (val == 1) {
        format = "<span background=\"#ffff00\" foreground=\"#000000\"> %s </span>";
    }
    else {
        format = "<span background=\"#616161\" foreground=\"#000000\"> %s </span>"; 
    }
    markup = g_markup_printf_escaped(format, text);
    gtk_label_set_markup(GTK_LABEL(label), markup);
}

void colorLabels() {
    colorizeLabel(scoreLetter(guessa[0], 0), 0, letter1);
    colorizeLabel(scoreLetter(guessa[1], 1), 1, letter2);
    colorizeLabel(scoreLetter(guessa[2], 2), 2, letter3);
    colorizeLabel(scoreLetter(guessa[3], 3), 3, letter4);
    colorizeLabel(scoreLetter(guessa[4], 4), 4, letter5);
}