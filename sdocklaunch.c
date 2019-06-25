#include <gtk-2.0/gtk/gtk.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "config.h"

/* Saves a bit of typing */
#define main_win (GTK_WINDOW(window))

/* Spawns a new child process then exits */
static void
spawn_process(GtkWidget *app, gpointer data)
{
        char *ARGS[] = { (gchar *)data, NULL };
        if (fork() == 0)
                execvp(ARGS[0], ARGS);

        gtk_main_quit();
}

static gboolean
dock_exit(GtkWidget *widget, GdkEvent *event, gpointer data)
{
        gtk_main_quit();
        return FALSE;
}

/* Creates a button for a given app and attempts to assign an icon */
static void
add_app(GtkWidget *app_dock, GtkTooltips *tooltips,
        GtkWidget *app, char *appname)
{
        GtkWidget *image;

        app = gtk_button_new();
        gtk_tooltips_set_tip(tooltips, app, appname, NULL);
        g_signal_connect(app, "clicked", G_CALLBACK(spawn_process),
                         (gpointer)appname);

        image = gtk_image_new_from_icon_name(appname, GTK_ICON_SIZE_BUTTON);
        gtk_image_set_pixel_size(GTK_IMAGE(image), icon_size);

        gtk_button_set_image(GTK_BUTTON(app), image);
        gtk_box_pack_start(GTK_BOX(app_dock), app, TRUE, TRUE, 0);
}

static void
fill_dock(GtkWidget *app_dock, GtkTooltips *tooltips, GtkWidget *app)
{
        char *appname;
        char *delim = " ";

        /* Grab the first app from the list */
        appname = strtok(apps, delim);
        assert(appname != NULL && "The apps line cannot be empty!");

        while(appname != NULL) {
                add_app(app_dock, tooltips, app, appname);
                appname = strtok(NULL, delim);
        }
}

int
main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *app = NULL; /* Avoids warning about app being uninit'd */
    GtkWidget *app_dock;
    GtkTooltips *tooltips;

    /* Setting tooltips to NULL _seems_ to harmlessly disable them */
    tooltips = tooltips_enable ? gtk_tooltips_new() : NULL;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(main_win, "SDockLaunch");
    g_signal_connect(window, "delete-event", G_CALLBACK(dock_exit), NULL);

    gtk_window_set_position(main_win, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_resizable(main_win, FALSE);

    app_dock = gtk_hbox_new(TRUE, padding);
    gtk_container_add(GTK_CONTAINER(window), app_dock);

    fill_dock(app_dock, tooltips, app);

    gtk_widget_show_all(window);

    gtk_main ();

    return 0;
}
