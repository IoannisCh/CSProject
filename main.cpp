#include <gtkmm.h>
#include "webkit2/webkit2.h"

int main(int argc, char *argv[]) {
    // Initialize GTKmm
    Gtk::Main kit(argc, argv);

    // Create a window
    Gtk::Window window;
    window.set_default_size(800, 600);

    // Create a WebView widget
    WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(webView, "https://www.google.com");

    // Add the WebView to the window
    window.add(*Glib::wrap(GTK_WIDGET(webView)));

    // Show all widgets
    window.show_all();

    // Start the GTKmm main loop
    Gtk::Main::run(window);

    return 0;
}
