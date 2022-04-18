#include "ui/banner.h"
#include "ui/box.h"
#include "ui/window.h"
#include "ui/format.h"

void wordleBanner() {
    GtkWidget 
    *tRow = gtk_list_box_row_new(),
    *tBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5),
    *wordleText = gtk_label_new("Wordle");
    formatWordleBanner(GTK_LABEL(wordleText));
    gtk_container_add(GTK_CONTAINER(tRow), tBox);
    gtk_box_pack_start(GTK_BOX(tBox), wordleText, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(list_box), tRow);
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(list_box));
    gtk_widget_show_all(GTK_WIDGET(tRow));
    gtk_widget_show_all(GTK_WIDGET(list_box));
}