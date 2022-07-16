#include "ui/main.h"
#include "ui/window.h"


int startWindow() {
    GtkApplication *app = gtk_application_new(
        "xyz.plooshi.wordle", 
        G_APPLICATION_FLAGS_NONE
    );
    g_signal_connect(app, "activate", G_CALLBACK(mainWindow), NULL);
    int status = g_application_run (G_APPLICATION (app), 0, NULL);
    g_object_unref(app);
    return status;
}