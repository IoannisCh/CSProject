#pragma once

#include <gtk/gtk.h>

#include "navigation_bar.h"
#include "web_view.h"

class BrowserWindow
{
public:
    BrowserWindow();
    ~BrowserWindow();

    void create();

private:
    GtkWidget* window;

    NavigationBar navigationBar;
    WebView webView;

    static void killWindow(GtkWidget* widget, gpointer data);
    static gboolean killWebView(WebView* webView, GtkWidget* window);
};