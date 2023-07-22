#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Create a WebView widget
    WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(webView, "https://www.google.com");

    // Add the WebView to the window
    //window.addWidget(GTK_WIDGET(webView));

    // Show the window
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
