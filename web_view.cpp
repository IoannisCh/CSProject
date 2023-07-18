#include <web_view.h>

WebView::WebView() : webView(nullptr) {}

WebView::~WebView() {
    if (webBiew) 
        g_object_unref(webBiew);
}

void WebView::create() {
    webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_url(webView, "https://www.google.com");
    g_signal_connect(webView, "notify::title", G_CALLBACK(onTitleChanged), nullptr);
}

GtkWidget* WebView::getWidget() const {
    return GTK_WIDGET(widget);
}

void WebView::onTitleChanged(WebKitWebView* webView, GParamSpec* pspec, GtkWidget* title){
    const gchar* pageTitle = webkit_web_view_get_title(webView);
    gtk_label_set_text(GTK_LABEL(title), pageTitle);
}