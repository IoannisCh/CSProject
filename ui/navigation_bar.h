#ifndef NAVIGATION_BAR_H
#define NAVIGATION_BAR_H

#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <vector>
#include "navigation_bar.h"

class BrowserController;

class NavigationBar {
public:
    NavigationBar(BrowserController* controller);

private:
    BrowserController* controller;

};

#endif // NAVIGATION_BAR_H