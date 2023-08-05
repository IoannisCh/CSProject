#ifndef NAVIGATION_BAR_H
#define NAVIGATION_BAR_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <vector>
#include "navigation_bar.h"
#include "bookmark_button.h"

class NavigationBar {
    public:
        NavigationBar();
        ~NavigationBar();
        void create();
        GtkWidget* getWidget() const;

    private:
        GtkWidget* toolbar;
        BookmarkButton bookmarkButton;

        GtkToolItem *newTb;
        GtkToolItem *openTb;
        GtkToolItem *saveTb;
        GtkToolItem *sep;
        GtkToolItem *exitTb;
};

#endif // NAVIGATION_BAR_H