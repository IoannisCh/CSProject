#include "web_view.h"

WebView::WebView() : webView(nullptr) {}

void WebView::create() {
    if (WebView != nullptr)
        return;

        webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
}

GtkWidget* WebView::getWidget() const {
    return webView ? GTK_WIDGET(webView) : nullptr;
}