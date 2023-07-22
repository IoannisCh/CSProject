#ifndef BROWSER_WINDOW_H
#define BROWSER_WINDOW_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <vector>
#include "navigation_bar.h"
#include "web_view.h"

class BrowserWindow{
    public:
        BrowserWindow();
        ~BrowserWindow();
        void create();

    private:
        GtkWidget* window;
        NavigationBar navigationBar;
        WebView* webView;
};

#endif // BROWSER_WINDOW_H