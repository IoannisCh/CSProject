#ifndef NAVIGATION_BAR_H
#define NAVIGATION_BAR_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <vector>
#include <bookmark_button.h>

class NavigationBar {
    public:
        NavigationBar();
        ~NavigationBar();
        void create();
        GtkWidget* getWidget() const;

    private:
        GtkWidget* toolbar;
        BookmarkButton* bookmarkButton;
};

#endif // NAVIGATION_BAR_H