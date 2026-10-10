#ifndef NAVIGATION_BAR_H
#define NAVIGATION_BAR_H

#include <gtk/gtk.h>

class BrowserController;

class NavigationBar {
    public:
        explicit NavigationBar(BrowserController* controller);

        void create():
        GtkWidget* get_widget() const;

    private:
        BrowserController* controller_;
        GtkWidget* toolbar;
        GtkWidget* addressEntry;
    
    static void onGoClicked(GtkButton* button, gpointer user_data);
    static void onAddressEntryActivate(GtkEntry* entry, gpointer user_data);
    static void onBackClicked(GtkButton* button, gpointer user_data);
    static void onForwardClicked(GtkButton* button, gpointer user_data);
    static void onReloadClicked(GtkButton* button, gpointer user_data);
}



#endif // NAVIGATION_BAR_H