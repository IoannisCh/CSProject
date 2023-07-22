#include "browser_window.h"

BrowserWindow::BrowserWindow() : window(nullptr) {}

BrowserWindow::~BrowserWindow()
{
    if (window)
    {
        gtk_accel_group_new();
    }
}

void BrowserWindow::create()
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    int w = 800;
    int h = 600;
    //gint* w_p = &w;
    //gint* h_p = &h;
    gtk_window_get_default_size(GTK_WINDOW(window), &w, &h);

    navigationBar.create();
    webView->create();

    GtkWidget* mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(mainBox), navigationBar.getWidget(), FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(mainBox), webView->getWidget(), TRUE, TRUE, 0);


    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    // KZ commented
    //gtk_container.addWidget(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), mainBox, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
}