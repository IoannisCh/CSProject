#include "WebKitWrapper.h"
#include <webkit2/webkit2.h>

WebKitWrapper::WebKitWrapper(WebKitWebView* View)
    : webView(View){}

void WebKitWrapper::loadURL(const std::string& url)
{
    webkit_web_view_load_uri(webView, url.c_str());   
}

void WebKitWrapper::goBack()
{
    webkit_web_view_go_back(webView);
}

void WebKitWrapper::goForward()
{
    webkit_web_view_go_forward(webView);
}

void WebKitWrapper::reload()
{
    webkit_web_view_reload(webView);
}