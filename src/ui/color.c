#include "ui/color.h"
#include "guess.h"
#include "score.h"
#include "ui/labels.h"
#include "ui/keyboard.h"
#include "ui/box.h"

int oskMap(int key) {
    char *keyMap = "qwertyuiopasdfghjklzxcvbnm";
    char output[] = "";
    for(int i = 0; i < 26; i++) {
        if ((char)keyMap[i] == (char)key + 97) {
            return i;
        }
    }
    return -1;
}

void colorizeOsk(int val, int i) {
    int fixedI = oskMap(i);
    GtkWidget *btn = gtk_grid_get_child_at(GTK_GRID(keyboardGrid), getLeft(fixedI), getTop(fixedI));
    if (val == 2) {
        gtk_widget_set_name(btn, "btnCorrect");
    }
    else if (val == 1) {
        gtk_widget_set_name(btn, "btnWrongSpot");
    }
    else {
        gtk_widget_set_name(btn, "btnNotIn");
    }
    gtk_grid_attach(GTK_GRID(keyboardGrid), btn, getLeft(fixedI), getTop(fixedI), 1, 1);
}

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

void colorOsk() {
    for (int i = 0; i < 5; i++) colorizeOsk(scoreLetter(guessa[i], i), ((int)guess[i]) - 97);
}