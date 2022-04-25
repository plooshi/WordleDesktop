#include "ui/keyboard.h"
#include "ui/box.h"

struct key
{
    gint id;
    GtkWidget *button;
};

static const gchar letters[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
static const gchar *kbLayout[3] = {
    "QWERTYUIOP",
    "ASDFGHJKL",
    "ZXCVBNM"
};
static gchar single_char[2] = {'A', '\0'};
GArray *keyboard;
GtkWidget *keyboardGrid;

int getTop(int i)
{
    return (i < 10 ? 0 : (i < 19 ? 1 : 2));
}

int getLeft(int i)
{
    return i < 10 ? i : i < 19 ? i - 10
                               : i - 18;
}

void keyboardInit()
{
    struct key k1;
    keyboard = g_array_new(FALSE, FALSE, sizeof(struct key));
    for (int j = 0; j < 26; j++)
    {
        single_char[0] = letters[j];
        k1.id = j;
        k1.button = gtk_button_new_with_label(single_char);
        g_array_append_val(keyboard, k1);
    }

    struct key *p1 = NULL;

    GtkWidget *grid1 = gtk_grid_new();
    for (int i = 0; i < 26; i++)
    {
        p1 = &g_array_index(keyboard, struct key, i);
        gtk_grid_attach(GTK_GRID(grid1), p1->button, getLeft(i), getTop(i), 1, 1);
    }

    keyboardGrid = gtk_grid_new();
    
    gtk_grid_attach(GTK_GRID(keyboardGrid), grid1, 0, 0, 1, 1);
    gtk_container_add(GTK_CONTAINER(list_box), keyboardGrid);
    g_array_free(keyboard, TRUE);
}