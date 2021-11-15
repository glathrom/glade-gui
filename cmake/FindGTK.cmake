# this is where the license notice would go

find_path(GTK_INCLUDE_DIRS "gtk/gtk.h"
    PATHS /usr/include/gtk-3.0
    DOC "gtk include path"
)

message(STATUS "gtk include dirs = ${GTK_INCLUDE_DIRS}")

find_path(GTK_LIBRARY_DIR 
    NAMES gtk-3
    PATHS /usr/lib/x86_64-linux-gnu
)

find_library( GTK_LIBRARY
    NAMES gtk-3
    PATHS /usr/lib/x86_64-linux-gnu
)

list(APPEND GTK_LINK_OPTIONS "-pthread" "-rdynamic")

set(GTK_FOUND 1)

add_library(GTK INTERFACE IMPORTED)

