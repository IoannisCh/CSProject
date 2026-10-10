#include "navigation_bar.h"
#include "../core/BrowserController.h"

#include <string>

NavigationBar::NavigationBar(BarowserController* controller) : controller_(controller), toolbar(nullptr), addressEntry(nullptr) {}

void NavigationBar::create(){
    toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    GtkWidget* backButton = gtk_button_new_with_label("Back");
    GtkWidget* forwardButton = gtk_button_new_with_label("Forward");
    GtkWidget* reloadButton = gtk_button_new_with_label("Reload");
    GtkWidget* goButton = gtk_button_new_with_label("Go");

    addressEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(addressEntry), "Enter a URL"
    )
    gtk_entry_set_activates_default(GTK_ENTRY(addressEntry), TRUE);

    gtk_box_pack_start(GTK_BOX(toolbar), backButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(toolbar), forwardButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(toolbar), reloadButton, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(toolbar), addressEntry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(toolbar), goButton, FALSE, FALSE, 0);

    g_signal_connect(backButton, "clicked", G_CALLBACK(onBackClicked), this);
    g_signal_connect(forwardButton, "clicked", G_CALLBACK(onForwardClicked), this);
    g_signal_connect(reloadButton, "clicked", G_CALLBACK(onReloadClicked), this);
    g_signal_connect(goButton, "clicked", G_CALLBACK(onGoClicked), this);
    g_signal_connect(addressEntry, "activate", G_CALLBACK(onAddressEntryActivate), this);
}

GtkWidget* NavigationBar::get_widget() const {
    return toolbar;
}

void NavigationBar::onGoClicked(GtkButton* , gpointer user_data) {
    auto* bar = static_cast<NavigationBar*>(user_data);

    if (bar->addressEntry == nullptr || bar->controller == nullptr)
        return;

    const gchar* text = gtk_entry_get_text(GTK_ENTRY(bar->addressEntry));

    std::string url = text ? text : "";

    if (url.empty())
        return;

    if (url.find("://") == std::string::npos && url.rfind("about:", 0) != 0) {
        url = "http://" + url;
    }

    bar->controller_->navigate(url);
}

void NavigationBar::onAddressEntryActivate(GtkEntry*, gpointer data) {
    onGoClicked(nullptr, data);
}

void NavigationBar::onBackClicked(GtkButton*, gpoineter data) {
    auto* bar = static_cast<NavigationBar*>(data);
    if (bar->controller) 
        bar->controller_->back();
}

void NavigatonBar::onForwardClicked(GtkButton*, gpointer data) {
    auto* bar = static_cast<NavigationBar*>(data);
    if (bar->controller) 
        bar->controller_->forward();
}

void NavigationBar::onReloadClicked(GtkButton*, gpointer data) {
    auto* bar = static_cast<NavigationBar*>(data);
    if (bar->controller) 
        bar->controller_->reload();
}

