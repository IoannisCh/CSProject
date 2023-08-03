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
#include "bookmark_button.h"

BookmarkButton::BookmarkButton() : button(nullptr){}

BookmarkButton::~BookmarkButton(){
    if (button)
    {
        gtk_widget_destroy(button);
    }
}

void BookmarkButton::create()
{
    button = gtk_button_new_with_label("Bookmark");
    //g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(onButtonClicked), nullptr);
}

GtkWidget* BookmarkButton::getWidget() const
{
    return button;
}

/*
void BookmarkButton::onButtonClicked(GTkButton* button, WebKitWebView* webView)
{
    const gchar* currentUri = webkit_web_view_get_uri(webView);
    g_print("Bookmark added: %s\n", currentUri);
}
*/