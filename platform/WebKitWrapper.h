#pragma once
#include <string>

typedef struct _WebKitWebView WebKitWebView;

class WebKitWrapper
{
public:
    WebKitWrapper(WebKitWebView* View);

    void loadURL(const std::string& url);
    void goBack();
    void goForward();
    void reload();

private:
    WebKitWebView* webView;
};