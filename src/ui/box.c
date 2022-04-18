#include "ui/box.h"
#include <stdbool.h>

GtkListBox *list_box;

void boxInit() {
    list_box = GTK_LIST_BOX(gtk_list_box_new());
    gtk_list_box_set_selection_mode(list_box, false);
}