#include <giomm.h>
#include <glibmm.h>

#include <iostream>

const std::string DESKTOP_INTERFACE_SCHEMA_ID = "org.gnome.desktop.interface";

Glib::RefPtr<Gio::Settings> settings;

/**
 * Determines if a theme name indicates it is a dark theme (ends in -dark)
 */
bool is_dark_theme(Glib::ustring theme_name) {
    auto theme = theme_name.lowercase();
    return Glib::str_has_suffix(theme, "-dark");
}

void gtk_theme_changed(Glib::ustring val) {
    // retrieve the new value
    auto theme = settings->get_string("gtk-theme");
    // check if the new theme is a dark or light theme
    auto value = is_dark_theme(theme) ? "dark" : "light";

    // print and flush to stdout
    std::cout << value << std::endl;
}

int main() {
    Glib::init();
    Glib::RefPtr<Glib::MainLoop> loop = Glib::MainLoop::create();

    // create a settings object for the desktop interface schema
    settings = Gio::Settings::create(DESKTOP_INTERFACE_SCHEMA_ID);
    // connect to the gtk-theme property to listen for changes
    settings->signal_changed("gtk-theme")
        .connect(sigc::ptr_fun(&gtk_theme_changed));

    // call the event handler at first run to print the current theme status
    gtk_theme_changed("gtk-theme");

    // run the event loop
    loop->run();

    return 0;
}
