#include <gtk/gtk.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Initialize GTK+
    gtk_init(&argc, &argv);

    // Create the browser window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Web Browser");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a WebView widget
    GtkWidget *webview = gtk_web_view_new();
    gtk_container_add(GTK_CONTAINER(window), webview);

    // Load a default URL
    const gchar *default_url = "https://www.example.com";
    gtk_web_view_load_uri(GTK_WEB_VIEW(webview), default_url);

    // Show all the widgets
    gtk_widget_show_all(window);

    // Run the main GTK+ loop
    gtk_main();

    return 0;
}
