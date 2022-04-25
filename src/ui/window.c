#include "ui/window.h"
#include "ui/box.h"
#include "ui/banner.h"
#include "ui/rows.h"
#include "ui/keyboard.h"
#include "input.h"
#include <stdbool.h>

GtkWidget *window;

void mainWindow(GtkApplication* app, gpointer user_data)
{
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Wordle");
    gtk_window_set_resizable(GTK_WINDOW(window), false);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "key-press-event", G_CALLBACK(handleKeys), NULL);
    boxInit();
    wordleBanner();
    formattingRow();
    keyboardInit();
    formattingRow();
    guessRow();
    gtk_widget_show_all(GTK_WIDGET(list_box));
    gtk_widget_show_all(window);
}