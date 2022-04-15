#include "event.h"
#include "gui.h"
#include "common.h"


GtkWidget *letter1;
GtkWidget *letter2;
GtkWidget *letter3;
GtkWidget *letter4;
GtkWidget *letter5;
GtkWidget *window;

void colorizeOut(int val, GtkWidget *label) {
    char *format;
    gchar *markup;
    const gchar *text = gtk_label_get_text(GTK_LABEL(label));
    if (val == 2) {
        format="<span background=\"#76ff03\" foreground=\"#000000\">%s </span>";
        markup=g_markup_printf_escaped(format,text);
    }
    else if (val == 1) {
        format="<span background=\"#ffff00\" foreground=\"#000000\">%s </span>";
        markup=g_markup_printf_escaped(format,text);
    }
    else {
        format="<span background=\"#616161\" foreground=\"#000000\">%s </span>";
        markup=g_markup_printf_escaped(format,text);
    }
    gtk_label_set_markup(GTK_LABEL(label), markup);
}

void colorLabels() {
    colorizeOut(scoreLetter(guessa[0], 0), letter1);
    colorizeOut(scoreLetter(guessa[1], 1), letter2);
    colorizeOut(scoreLetter(guessa[2], 2), letter3);
    colorizeOut(scoreLetter(guessa[3], 3), letter4);
    colorizeOut(scoreLetter(guessa[4], 4), letter5);
}

GtkWidget *guessRow(GtkListBox *list_box) {
    GtkWidget
    *row = gtk_list_box_row_new(),
    *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    updateGuessArray();

    letter1 = gtk_label_new(guessa[0]);
    letter2 = gtk_label_new(guessa[1]);
    letter3 = gtk_label_new(guessa[2]);
    letter4 = gtk_label_new(guessa[3]);
    letter5 = gtk_label_new(guessa[4]);
    
    /*colorizeOut(scoreLetter(guessa[0], 0), letter1);
    colorizeOut(scoreLetter(guessa[1], 1), letter2);
    colorizeOut(scoreLetter(guessa[2], 2), letter3);
    colorizeOut(scoreLetter(guessa[3], 3), letter4);
    colorizeOut(scoreLetter(guessa[4], 4), letter5);*/

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
    GtkWidget *list_box = gtk_list_box_new();
    GtkWidget *row = guessRow(GTK_LIST_BOX(list_box));
    gtk_container_add(GTK_CONTAINER(window), list_box);
    gtk_widget_show_all(row);
    gtk_widget_show_all(list_box);
}


static void render(GtkApplication* app, gpointer user_data)
{
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Wordle");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), NULL);
    createRow();
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