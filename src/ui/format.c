#include "ui/format.h"

void formatLabel(GtkLabel *label) {
    PangoAttrList *attrlist = pango_attr_list_new();

    PangoFontDescription * font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, 20 * PANGO_SCALE);
    PangoAttribute * attr = pango_attr_font_desc_new(font_desc);

    pango_attr_list_insert(attrlist, attr);
    gtk_label_set_attributes(label, attrlist);
    gtk_widget_set_hexpand (GTK_WIDGET(label), TRUE);
}

void formatWordleBanner(GtkLabel *label) {
    PangoAttrList *attrlist = pango_attr_list_new();

    PangoFontDescription * font_desc = pango_font_description_new();
    pango_font_description_set_size(font_desc, 30 * PANGO_SCALE);
    PangoAttribute * attr = pango_attr_font_desc_new(font_desc);

    pango_attr_list_insert(attrlist, attr);
    gtk_label_set_attributes(label, attrlist);
    gtk_widget_set_hexpand (GTK_WIDGET(label), TRUE);
}