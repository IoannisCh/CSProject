#include "gtk/gtk.h>
#include "webkit/webkit.h"

int main(int argc, char *argv[]) {
    // Initialize GTKmm
    Gtk::Main kit(argc, argv);

    // Create a window
    Gtk::Window window;
    window.set_default_size(800, 600);

    // Create a WebView widget
    WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webView->load_uri("https://www.example.com");

    // Add the WebView to the window
    window.add(*GTK_WIDGET(webView));

    // Show all widgets
    window.show_all();

    // Start the GTKmm main loop
    Gtk::Main::run(window);

    return 0;
}
