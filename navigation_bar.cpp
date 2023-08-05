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
#include "navigation_bar.h"
#include "bookmark_button.h"

NavigationBar::NavigationBar() : toolbar(nullptr){}

NavigationBar::~NavigationBar(){
    if(toolbar)
     gtk_widget_destroy(toolbar);
}

void NavigationBar::create(){

    // Attempt to include toolbar
    //gchar* label = g_strdup("Bar");
    //toolbar = gtk_frame_new(label);

    // Toolbar withiou name:
    toolbar = gtk_toolbar_new();
    
    //====================
    // Add toolbar options
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
    newTb = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

    openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

    saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

    sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1); 

    exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

    g_signal_connect(G_OBJECT(exitTb), "clicked", 
                     G_CALLBACK(gtk_main_quit), NULL);

    //====================
    
    gtk_toolbar_set_show_arrow(GTK_TOOLBAR(toolbar), TRUE);

    bookmarkButton.create();

    gtk_container_add(GTK_CONTAINER(toolbar), bookmarkButton.getWidget());  
}

GtkWidget* NavigationBar::getWidget() const {
    return toolbar;
}