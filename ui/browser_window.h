#ifndef BROWSER_WINDOW_H
#define BROWSER_WINDOW_H

#include <gtk/gtk.h>
#include <memory>

#include "navigation_bar.h"
#include "web_view.h"

class BrowserController;
class WebKitWrapper;

class BrowserWindow {
public:
    BrowserWindow();
    ~BrowserWindow();

BrowserWindow(const BrowserWindow&) = delete;
    BrowserWindow& operator=(const BrowserWindow&) = delete;

    void create();

private:
    GtkWidget* window;
    
    WebView webView;
    std::unique_ptr<WebKitWrapper> webKitWrapper;
    std::unique_ptr<BrowserController> browserController;
    std::unique_ptr<NavigationBar> navigationBar;

    static void onWindowDestroy(GtkWidget* widget, gpointer data);
};


#endif // BROWSER_WINDOW_H