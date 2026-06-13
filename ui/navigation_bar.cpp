#include "navigation_bar.h"
#include "bookmark_button.h"

NavigationBar::NavigationBar() : toolbar(nullptr){}

NavigationBar::NavigationBar(BrowserController* controller)
    : controller(controller){}


void on_go_clicked(GtkButton*, gpointer data) {

}

GtkWidget* NavigationBar::getWidget() const {
    return toolbar;
}