#ifndef __GTK_HELLO_H__
#define __GTK_HELLO_H__

#include <gtk/gtk.h>

void print_hello (GtkWidget *widget, gpointer data);
void activate (GtkApplication *app, gpointer user_data);
int gtk_hello(int argc, char **argv);

#endif // __GTK_HELLO_H__