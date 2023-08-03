/*
    <Web browser>
    Copyright (C) <2023>  <IoannisCh>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "web_view.h"

WebView::WebView() : webView(nullptr) {}

WebView::~WebView() {
    if (webView)
    { 
        g_object_unref(webView);
    }    
}

void WebView::create() {
    webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
    webkit_web_view_load_uri(webView, "https://www.google.com");
    g_signal_connect(webView, "notify::title", G_CALLBACK(onTitleChanged), nullptr);
}

GtkWidget* WebView::getWidget() const 
{
    return GTK_WIDGET(webView);
}

void WebView::onTitleChanged(WebKitWebView* webView, GParamSpec* pspec, GtkWidget* title){
    const gchar* pageTitle = webkit_web_view_get_title(webView);
    gtk_label_set_text(GTK_LABEL(title), pageTitle);
}