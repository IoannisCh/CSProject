#include "navigation_bar.h"

#include "../core/BrowserController.h"

NavigationBar::NavigationBar(BrowserController* controller)
    : controller_(controller),
      toolbar(nullptr),
      addressEntry(nullptr)
{
}

void NavigationBar::create()
{
    if (toolbar != nullptr) {
        return;
    }

    // Create the navigation toolbar.
    toolbar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    // Back button.
    GtkWidget* backButton = gtk_button_new_with_label("Back");
    g_signal_connect(
        backButton,
        "clicked",
        G_CALLBACK(NavigationBar::onBackClicked),
        this
    );
    gtk_box_pack_start(GTK_BOX(toolbar), backButton, FALSE, FALSE, 0);

    // Forward button.
    GtkWidget* forwardButton = gtk_button_new_with_label("Forward");
    g_signal_connect(
        forwardButton,
        "clicked",
        G_CALLBACK(NavigationBar::onForwardClicked),
        this
    );
    gtk_box_pack_start(GTK_BOX(toolbar), forwardButton, FALSE, FALSE, 0);

    // Reload button.
    GtkWidget* reloadButton = gtk_button_new_with_label("Reload");
    g_signal_connect(
        reloadButton,
        "clicked",
        G_CALLBACK(NavigationBar::onReloadClicked),
        this
    );
    gtk_box_pack_start(GTK_BOX(toolbar), reloadButton, FALSE, FALSE, 0);

    // Address bar.
    addressEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(
        GTK_ENTRY(addressEntry),
        "Enter a URL..."
    );
    gtk_entry_set_activates_default(GTK_ENTRY(addressEntry), TRUE);
    gtk_widget_set_hexpand(addressEntry, TRUE);

    g_signal_connect(
        addressEntry,
        "activate",
        G_CALLBACK(NavigationBar::onAddressEntryActivate),
        this
    );

    gtk_box_pack_start(
        GTK_BOX(toolbar),
        addressEntry,
        TRUE,
        TRUE,
        5
    );

    // Go button.
    GtkWidget* goButton = gtk_button_new_with_label("Go");
    g_signal_connect(
        goButton,
        "clicked",
        G_CALLBACK(NavigationBar::onGoClicked),
        this
    );
    gtk_box_pack_start(GTK_BOX(toolbar), goButton, FALSE, FALSE, 0);
}

GtkWidget* NavigationBar::get_widget() const
{
    return toolbar;
}

void NavigationBar::onGoClicked(GtkButton* button, gpointer user_data)
{
    (void)button;

    auto* bar = static_cast<NavigationBar*>(user_data);

    if (bar == nullptr ||
        bar->addressEntry == nullptr ||
        bar->controller_ == nullptr) {
        return;
    }

    const gchar* text =
        gtk_entry_get_text(GTK_ENTRY(bar->addressEntry));

    if (text == nullptr || *text == '\0') {
        return;
    }

    bar->controller_->navigate(text);
}

void NavigationBar::onAddressEntryActivate(
    GtkEntry* entry,
    gpointer user_data)
{
    (void)entry;

    onGoClicked(nullptr, user_data);
}

void NavigationBar::onBackClicked(GtkButton* button, gpointer user_data)
{
    (void)button;

    auto* bar = static_cast<NavigationBar*>(user_data);

    if (bar != nullptr && bar->controller_ != nullptr) {
        bar->controller_->back();
    }
}

void NavigationBar::onForwardClicked(
    GtkButton* button,
    gpointer user_data)
{
    (void)button;

    auto* bar = static_cast<NavigationBar*>(user_data);

    if (bar != nullptr && bar->controller_ != nullptr) {
        bar->controller_->forward();
    }
}

void NavigationBar::onReloadClicked(GtkButton* button, gpointer user_data)
{
    (void)button;

    auto* bar = static_cast<NavigationBar*>(user_data);

    if (bar != nullptr && bar->controller_ != nullptr) {
        bar->controller_->reload();
    }
}
