#include "ui/color.h"
#include "guess.h"
#include "score.h"
#include "ui/labels.h"
#include "ui/keyboard.h"

void colorizeOsk(int val, int i) { 
    GtkWidget *btn = gtk_grid_get_child_at(GTK_GRID(keyboardGrid), getLeft(i), getTop(i));
    char *color;

    if (val == 2) {
        color = "#76ff03";
    } else if (val == 1) {
        color = "#ffff00";
    } else {
        color = "#616161";
    }
    char *css = "button { background-color: %s; background-image: none; }";
    char *fmt = g_strdup_printf(css, color);
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider, fmt, -1, NULL);
    GtkStyleContext *ctx = gtk_widget_get_style_context(btn);
    gtk_style_context_add_provider(ctx, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_free(fmt);
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
    colorizeOsk(scoreLetter(guessa[0], 0), ((int)guess[0]) - 96);
    colorizeOsk(scoreLetter(guessa[1], 1), ((int)guess[1]) - 96);
    colorizeOsk(scoreLetter(guessa[2], 2), ((int)guess[2]) - 96);
    colorizeOsk(scoreLetter(guessa[3], 3), ((int)guess[3]) - 96);
    colorizeOsk(scoreLetter(guessa[4], 4), ((int)guess[4]) - 96);
}