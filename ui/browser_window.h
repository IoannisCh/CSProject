#pragma once 

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
        GtkWidget* webView;

       static void on_destroy(GtkWidget* widget, gpointer data);
};
