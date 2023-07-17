#include "navigation_bar.h"

NavigationBar::NavigationBar() : toolbar(nullptr){}

NavigationBar::~NavigationBar(){
    if(toolbar)
     gtk_widget_destroy(toolbar);
}

void NavigationBar::create(){
    toolbar = gtk_create_new();
    gtk_toolbar_set_show_arrow(GTK_TOOLBAR(toolbar), TRUE);

    bookmarkButton.create();

    gtk_container_add(GTK_CONTAINER(toolbar), bookmarkButton.getWdiget());  
}

GtkWidget* NavigationBar::getWidget() const {
    return toolbar;
}