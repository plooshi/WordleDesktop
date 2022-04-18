#include "ui/labels.h"
#include "guess.h"

GtkWidget *letter1;
GtkWidget *letter2;
GtkWidget *letter3;
GtkWidget *letter4;
GtkWidget *letter5;

void resetLabels() {
    letter1 = gtk_label_new("");
    letter2 = gtk_label_new("");
    letter3 = gtk_label_new("");
    letter4 = gtk_label_new("");
    letter5 = gtk_label_new("");
}
void refreshLabels() {
    gtk_label_set_text(GTK_LABEL(letter1), guessa[0]);
    gtk_label_set_text(GTK_LABEL(letter2), guessa[1]);
    gtk_label_set_text(GTK_LABEL(letter3), guessa[2]);
    gtk_label_set_text(GTK_LABEL(letter4), guessa[3]);
    gtk_label_set_text(GTK_LABEL(letter5), guessa[4]);
}