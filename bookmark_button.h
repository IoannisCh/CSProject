#ifndef BOOKMARK_BUTTON_H
#define BOOKMARK_BUTTON_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <vector>

class WebkitWebView;

class BookmarkButton{
    public:
    BookmarkButton();
    ~BookmarkButton();
    void create();
    GtkWidget* getWidget() const;
    
    //static void onButtonClicked(GtkButton* button, WebkitWebView* webview);

    private:

    GtkWidget* button; 
};

#endif // BOOKMARK_BUTTON_H