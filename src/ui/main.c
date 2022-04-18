#include "ui/main.h"
#include "ui/window.h"

#ifdef _WIN32
int startWindow()
#else
int startWindow(int argc, char *argv[]) 
#endif
{
    GtkApplication *app = gtk_application_new(
        "xyz.plooshi.wordle", 
        G_APPLICATION_FLAGS_NONE
    );
    g_signal_connect(app, "activate", G_CALLBACK(mainWindow), NULL);
#ifdef _WIN32
    int status = g_application_run (G_APPLICATION (app), 0, NULL);
#else
    int status = g_application_run (G_APPLICATION (app), argc, argv);
#endif
    g_object_unref(app);
    return status;
}