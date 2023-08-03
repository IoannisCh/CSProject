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

NavigationBar::NavigationBar() : toolbar(nullptr){}

NavigationBar::~NavigationBar(){
    if(toolbar)
     gtk_widget_destroy(toolbar);
}

void NavigationBar::create(){
    gchar* label = g_strdup ("Test");
    toolbar = gtk_frame_new(label);
    gtk_toolbar_set_show_arrow(GTK_TOOLBAR(toolbar), TRUE);

    //bookmarkButton.create();

    //gtk_container_add(GTK_CONTAINER(toolbar), bookmarkButton.getWdiget());  
}

GtkWidget* NavigationBar::getWidget() const {
    return toolbar;
}