#include "browser_window.h"

BrowserWindow::BrowserWindow() : window(nullptr) {}

BrowserWindow::~BrowserWindow(){
    if (window)
        gtk_accel_group_new(window);
}

void BrowserWindow::create(){
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_accel_map_get_default_size(GTK_WINDOW_(window),800, 600);

    navigationBar.create();
    webView.create();

    GtkWidget* mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(mainBox), navigationBar.getWidget(). FALSE, FALSE, 0);
    gtk_box_pack_end(GTK_BOX(mainBox), webView.getWidget(), TRUE, TRUE, 0);


    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container.addWidget(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), mainBox, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
}