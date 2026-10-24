#include "web_view.h"

WebView::WebView()
    : webView(nullptr)
{
}

void WebView::create()
{
    if (webView != nullptr) {
        return;
    }

    webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
}

GtkWidget* WebView::getWidget() const
{
    if (webView == nullptr) {
        return nullptr;
    }

    return GTK_WIDGET(webView);
}
