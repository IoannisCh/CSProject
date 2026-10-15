#include "browser_window.h"

#include "../core/BrowserController.h"
#include "../platform/WebKitWrapper.h"

BrowserWindow::BrowserWindow()
    : window(nullptr)

{
}

BrowserWindow::~BrowserWindow() {
    if (window) 
        gtk_widget_destroy(window);
    
}

void BrowserWindow::create() 
{
   if (window != nullptr)
        return;

    webView.create();

    webKitWrapper = std::make_unique<WebKitWrapper>(
        WEBKIT_WEB_VIEW(webView.getWidget())    
    );

    controller = std::make_unique<BrowserController>(webKitWrapper.get());

    navigationBar = std::make_unique<NavigationBar>(controller.get());

    navigationBar->create();

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk _window_set_title(GTK_WINDOW(window), "RaCoon Browser");
    gtk_window_set_default_size(GTK_WINDOW(window), 1100, 750);

    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(window), layout);

    gtk_box_pack_start(GTK_BOX(layout), navigationBar->getWidget(), FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(layout), webView.getWidget(), TRUE, TRUE, 0);

    g_signal_connect(window, "destroy", G_CALLBACK(onWindowDestroy), this);

    controller->navigateTo("https://www.google.com");

    gtk_widget_show_all(window);

}

void BrowserWindow::onWindowDestroy(GtkWidget* widget, gpointer data) 
    {
        auto *browser = static_cast<BrowserWindow*>(data);
        browser->window = nullptr;

        gtk_main_quit();
    }
