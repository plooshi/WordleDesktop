#include "ui/rows.h"
#include "ui/labels.h"
#include "ui/box.h"
#include "ui/format.h"
#include "guess.h"

void formattingRow() {
    GtkWidget *row = gtk_list_box_row_new(),
    *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    gtk_container_add(GTK_CONTAINER(row), hbox);
    gtk_container_add(GTK_CONTAINER(list_box), row);

    gtk_widget_show_all(row);
}

void guessRow() {
    GtkWidget
    *row = gtk_list_box_row_new(),
    *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    updateGuessArray();

    resetLabels();
    
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
    gtk_widget_show_all(row);
}
