#include <stdlib.h>
#include <stdio.h>
#include <glib-object.h>
#include <gtk/gtk.h>

void on_button1_clicked(GtkButton *, GtkLabel *);

int main(int argc, char **argv){
    GtkWidget    *window;
    GtkWidget    *fixed1;
    GtkWidget    *button1;
    GtkWidget    *label1;
    GtkBuilder   *builder;
    
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("../res/gui/mywindow.glade");

    window = (GtkWidget *) gtk_builder_get_object(builder, "window");

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    fixed1 = (GtkWidget *) gtk_builder_get_object(builder, "fixed1");
    button1 = (GtkWidget *) gtk_builder_get_object(builder, "button1");
    label1 = (GtkWidget *) gtk_builder_get_object(builder, "label1");

    gtk_widget_show(window);

    gtk_main();

    return 0;
}


void on_button1_clicked(GtkButton *b, GtkLabel *label){
    GtkWidget* parent = gtk_widget_get_parent((GtkWidget *) b);
    printf("parent name = %s\n", gtk_widget_get_name(parent)); 

    gtk_label_set_text(label, "Hello World");
}
