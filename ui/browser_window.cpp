#include "browser_window.h"

#include "../core/BrowserController.h"
#include "../platform/WebKitWrapper.h"

BrowserWindow::BrowserWindow()
    : window(nullptr)
{
}

BrowserWindow::~BrowserWindow()
{
    if (window != nullptr) {
        gtk_widget_destroy(window);
    }
}

void BrowserWindow::create()
{
    if (window != nullptr) {
        return;
    }

    // Create the web view.
    webView.create();

    // Create the WebKit wrapper and controller.
    webKitWrapper = std::make_unique<WebKitWrapper>(
        WEBKIT_WEB_VIEW(webView.getWidget()));

    browserController =
        std::make_unique<BrowserController>(webKitWrapper.get());

    // Create the navigation bar.
    navigationBar =
        std::make_unique<NavigationBar>(browserController.get());

    navigationBar->create();

    // Create the main window.
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(
        GTK_WINDOW(window), "RaCoon Browser");

    gtk_window_set_default_size(
        GTK_WINDOW(window), 1100, 750);

    // Create a vertical layout.
    GtkWidget* layout =
        gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add(GTK_CONTAINER(window), layout);

    // Place the navigation bar above the web view.
    gtk_box_pack_start(
        GTK_BOX(layout),
        navigationBar->get_widget(),
        FALSE,
        FALSE,
        6);

    gtk_box_pack_start(
        GTK_BOX(layout),
        webView.getWidget(),
        TRUE,
        TRUE,
        0);

    // Handle the window closing event.
    g_signal_connect(
        window,
        "destroy",
        G_CALLBACK(onWindowDestroy),
        this);

    // Load the initial page.
    browserController->navigate("https://example.com");

    gtk_widget_show_all(window);
}

void BrowserWindow::onWindowDestroy(
    GtkWidget* widget,
    gpointer data)
{
    (void)widget;

    auto* browser = static_cast<BrowserWindow*>(data);
    browser->window = nullptr;

    gtk_main_quit();
}
