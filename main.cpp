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

BrowserWindow::BrowserWindow() 
    : window(nullptr), webView(nullptr) {}

BrowserWindow::~BrowserWindow() {}

void BrowserWindow::create() {
    // Create the main application window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "RaCoon Browserr");
    gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);

    // Create the web view
    webView = webkit_web_view_new();
    gtk_container_add(GTK_CONTAINER(window), webView);

    // Connect the destroy signal to quit the application
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {

    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Declare browser object
    BrowserWindow browser;

    // Create browser object
    browser.create();
    
    // Start the GTK main loop
    gtk_main();

    return 0;
}
