#ifndef WEB_VIEW_H
#define WEB_VIEW_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

class WebView{
    public:
        WebView();
        ~WebView();
        void create();
        GtkWidget* getWidget() const;

    private:
        WebKitWebView* webView;

        static void onTitleChanged(WebKitWebView* webView, GParamSpec* pspec, GtkWidget* title);
};

#endif // WEB_VIEW_H