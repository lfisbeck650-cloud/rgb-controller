#include <gtk/gtk.h>
#include <stdint.h>

#include "rgb.h"

static void color_changed(GtkColorChooser *chooser, gpointer data)
{
    GdkRGBA color;

    gtk_color_chooser_get_rgba(chooser, &color);

    uint8_t r = (uint8_t)(color.red * 255.0);
    uint8_t g = (uint8_t)(color.green * 255.0);
    uint8_t b = (uint8_t)(color.blue * 255.0);

    rgb_set_all(r, g, b);
}

static void activate(GtkApplication *app, gpointer data)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *color_button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "RGB Controller");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 250);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 15);
    gtk_widget_set_margin_top(box, 30);
    gtk_widget_set_margin_bottom(box, 30);
    gtk_widget_set_margin_start(box, 30);
    gtk_widget_set_margin_end(box, 30);

    gtk_container_add(GTK_CONTAINER(window), box);

    label = gtk_label_new("MEDION BEAST X25 RGB");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);

    color_button = gtk_color_button_new();
    gtk_color_chooser_set_use_alpha(
        GTK_COLOR_CHOOSER(color_button),
        FALSE
    );

    gtk_box_pack_start(
        GTK_BOX(box),
        color_button,
        FALSE,
        FALSE,
        0
    );

    g_signal_connect(
        color_button,
        "color-set",
        G_CALLBACK(color_changed),
        NULL
    );

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    if (rgb_open() < 0)
        return 1;

    rgb_set_pattern(
        RGB_PATTERN_SOLID,
        0x05,
        0x10
    );

    app = gtk_application_new(
        "com.lenny.rgbcontroller",
        G_APPLICATION_FLAGS_NONE
    );

    g_signal_connect(
        app,
        "activate",
        G_CALLBACK(activate),
        NULL
    );

    status = g_application_run(
        G_APPLICATION(app),
        argc,
        argv
    );

    g_object_unref(app);

    rgb_close();

    return status;
}