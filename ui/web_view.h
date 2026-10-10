#ifndef WEB_VIEW_H
#define WEB_VIEW_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

class WebView{
    public:
        WebView();
        
        void create();
        GtkWidget* getWidget() const;

    private:
        WebKitWebView* webView;
};

#endif // WEB_VIEW_H