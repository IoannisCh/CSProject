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
    //gtk_container.addWidget(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), mainBox, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
}