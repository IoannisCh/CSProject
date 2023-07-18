#include <bookmark_button.h>

BookmarkButton::BookmarkButton() : button(nullptr){}

BookmarkButton::~BookmarkButton(){
    if (button)
        gtk_widget_destroy(button);
}

void BookmarkButton::create(){
    button = gtk_button_new_with_label("Bookmark");
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLCBACK(onButtonClicked), nullptr);
}

GtkWidget* BookmarkButton::getWidget() const{
    return button;
}

void BookmarkButton::onButtonClicked(GTkButton* button, WebKitWebView* webView){
    const gchar* currentUri = webkit_web_view_get_uri(webView);
    g_print("Bookmark added: %s\n", currentUri);
}