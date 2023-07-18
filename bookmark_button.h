#ifndef BOOKMARK_BUTTON_H
#define BOOKMARK_BUTTON_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <vector>

class Bookmark{
    public:
    BookmarkButton();
    ~BookmarkButton();
    void create();
    GtkWidget* getWidget(); const;

    private:

    GtkWidget* button;

    static void onButtonClicked(GtkButton* button, WebkitWebView* webview);

};

#endif // BOOKMARK_BUTTON_H