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
#include <gtk/gtk.h>
#include <gtk/gtkfilechooser.h>
#include <webkit2/webkit2.h>
#include "browser_window.h"

int main(int argc, char *argv[]) {

    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Declare browser object
    BrowserWindow browser;

    // Create browser object
    browser.create();
    
    // Start the GTK main loop
    gtk_main();

    return 0;
}
