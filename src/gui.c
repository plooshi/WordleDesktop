#include "event.h"
#include "gui.h"
#include "common.h"


GtkWidget *letter1;
GtkWidget *letter2;
GtkWidget *letter3;
GtkWidget *letter4;
GtkWidget *letter5;
GtkWidget *window;
GtkListBox *list_box;

void colorizeOut(int val, int pos, GtkWidget *label) {
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
    colorizeOut(scoreLetter(guessa[0], 0), 0, letter1);
    colorizeOut(scoreLetter(guessa[1], 1), 1, letter2);
    colorizeOut(scoreLetter(guessa[2], 2), 2, letter3);
    colorizeOut(scoreLetter(guessa[3], 3), 3, letter4);
    colorizeOut(scoreLetter(guessa[4], 4), 4, letter5);
}

void formatLabel(GtkLabel *label) {
    PangoAttrList *attrlist = pango_attr_list_new();

    PangoFontDescription * font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, 20 * PANGO_SCALE);
    PangoAttribute * attr = pango_attr_font_desc_new(font_desc);

    pango_attr_list_insert(attrlist, attr);
    gtk_label_set_attributes(label, attrlist);
    gtk_widget_set_hexpand (GTK_WIDGET(label), TRUE);
}

GtkWidget *guessRow() {
    GtkWidget
    *row = gtk_list_box_row_new(),
    *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    updateGuessArray();

    letter1 = gtk_label_new("");
    letter2 = gtk_label_new("");
    letter3 = gtk_label_new("");
    letter4 = gtk_label_new("");
    letter5 = gtk_label_new("");
    
    /*colorizeOut(scoreLetter(guessa[0], 0), letter1);
    colorizeOut(scoreLetter(guessa[1], 1), letter2);
    colorizeOut(scoreLetter(guessa[2], 2), letter3);
    colorizeOut(scoreLetter(guessa[3], 3), letter4);
    colorizeOut(scoreLetter(guessa[4], 4), letter5);*/
    formatLabel(GTK_LABEL(letter1));
    formatLabel(GTK_LABEL(letter2));
    formatLabel(GTK_LABEL(letter3));
    formatLabel(GTK_LABEL(letter4));
    formatLabel(GTK_LABEL(letter5));

    gtk_container_add(GTK_CONTAINER(row), hbox);
    gtk_box_pack_start(GTK_BOX(hbox), letter1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), letter2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), letter3, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), letter4, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), letter5, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(list_box), row);
    return row;
}


void refreshLabels() {
    gtk_label_set_text(GTK_LABEL(letter1), guessa[0]);
    gtk_label_set_text(GTK_LABEL(letter2), guessa[1]);
    gtk_label_set_text(GTK_LABEL(letter3), guessa[2]);
    gtk_label_set_text(GTK_LABEL(letter4), guessa[3]);
    gtk_label_set_text(GTK_LABEL(letter5), guessa[4]);
}

void createRow() {
    letter1 = NULL;
    letter2 = NULL;
    letter3 = NULL;
    letter4 = NULL;
    letter5 = NULL;
    GtkWidget *row = guessRow();
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(list_box));
    gtk_widget_show_all(row);
}

void formatWordleText(GtkLabel *label) {
    PangoAttrList *attrlist = pango_attr_list_new();

    PangoFontDescription * font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, 30 * PANGO_SCALE);
    PangoAttribute * attr = pango_attr_font_desc_new(font_desc);

    pango_attr_list_insert(attrlist, attr);
    gtk_label_set_attributes(label, attrlist);
    gtk_widget_set_hexpand (GTK_WIDGET(label), TRUE);
}

GtkWidget *wordleBanner() {
    GtkWidget
    *tRow = gtk_list_box_row_new(),
    *tBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5),
    *tListBox = gtk_list_box_new(),
    *wordleText = gtk_label_new("Wordle");
    gtk_list_box_set_selection_mode(GTK_LIST_BOX(tListBox), false);
    formatWordleText(GTK_LABEL(wordleText));
    gtk_container_add(GTK_CONTAINER(tRow), tBox);
    gtk_box_pack_start(GTK_BOX(tBox), wordleText, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(tListBox), tRow);
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(tListBox));
    gtk_widget_show_all(GTK_WIDGET(tRow));
    gtk_widget_show_all(GTK_WIDGET(tListBox));
    return tListBox;
}

static void render(GtkApplication* app, gpointer user_data)
{
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Wordle");
    gtk_window_set_resizable(GTK_WINDOW(window), false);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), NULL);
    list_box = GTK_LIST_BOX(wordleBanner());
    createRow();
    gtk_widget_show_all(GTK_WIDGET(list_box));
    gtk_widget_show_all(window);
}

#ifdef _WIN32
int gtkMain()
#else
int gtkMain(int argc, char *argv[]) 
#endif
{
    GtkApplication *app = gtk_application_new(
        "xyz.plooshi.wordle", 
        G_APPLICATION_FLAGS_NONE
    );
    g_signal_connect(app, "activate", G_CALLBACK(render), NULL);
#ifdef _WIN32
    int status = g_application_run (G_APPLICATION (app), 0, NULL);
#else
    int status = g_application_run (G_APPLICATION (app), argc, argv);
#endif
    g_object_unref(app);
    return status;
}