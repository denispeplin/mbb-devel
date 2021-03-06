/* Copyright (C) 2010 Mikhail Osipov <mike.osipov@gmail.com> */
/* Published under the GNU General Public License V.2, see file COPYING */

#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <glib.h>

#include "xmltag.h"

typedef struct xml_parser XmlParser;

XmlParser *xml_parser_new(gboolean (*func)(XmlTag *, gpointer), gpointer data);
gboolean xml_parser_parse(XmlParser *parser, gchar *text, gssize text_len,
			  GError **error);
void xml_parser_free(XmlParser *parser);

#endif
