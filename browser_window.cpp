/*
    <Web browser>
    Copyright (C) <2023>  <IoannisCh>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "browser_window.h"

BrowserWindow::BrowserWindow() : window(nullptr) {}

BrowserWindow::~BrowserWindow()
{
    if (window)
    {
        gtk_widget_destroy(window);
    }
}

void BrowserWindow::create()
{
    // Initialise main browser window using gtk
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Provide window with dimesnsions on start up
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    
    // Create navigation bar
    navigationBar.create();

    // Create webview starting page
    webView.create();
    WebView* pwebView = &webView;
    GtkWidget* mainBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(mainBox), navigationBar.getWidget(), FALSE, FALSE, 7);
    gtk_box_pack_start(GTK_BOX(mainBox), webView.getWidget(), TRUE, TRUE, 0);


    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), mainBox, TRUE, TRUE, 0);

    // signals send when closing RaCoon browser
    g_signal_connect(window, "destroy", G_CALLBACK(killWindow), nullptr);
    g_signal_connect(pwebView, "close", G_CALLBACK(killWebView), window);

    //gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webView.getWidget()));
    gtk_widget_show_all(window);
}

void BrowserWindow::killWindow(GtkWidget* widget, GtkWidget* window)
{
    gtk_main_quit();
}

gboolean BrowserWindow::killWebView(WebView* webView, GtkWidget* window)
{
    gtk_widget_destroy(window);
    return TRUE;
}
