#include "event.h"

static void render(GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Window");
    gtk_window_set_default_size(GTK_WINDOW (window), 400, 300);
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