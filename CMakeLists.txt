project(Wordle)
cmake_minimum_required(VERSION 3.8)

if (MSVC)
if (!GTK_DIR)
message("GTK_DIR not set, dont question if there are errors. To set it please add -DGTK_DIR:PATH=<path to GTK and dependencies directory>")
endif()
include_directories(
    ${GTK_DIR}/include
    ${GTK_DIR}/include/gtk-3.0
    ${GTK_DIR}/include/glib-2.0
    ${GTK_DIR}/include/pango-1.0
    ${GTK_DIR}/include/harfbuzz
    ${GTK_DIR}/include/cairo
    ${GTK_DIR}/include/gdk-pixbuf-2.0
    ${GTK_DIR}/include/atk-1.0
    ${GTK_DIR}/lib/glib-2.0/include
)
link_directories(${GTK_DIR}/lib)
endif()

if (WIN32)
set(GUI_TYPE WIN32)
endif()

if (APPLE)
set(GUI_TYPE MACOSX_BUNDLE)
endif()

if (UNIX OR APPLE)
find_package(PkgConfig)
pkg_check_modules(GTK gtk+-3.0)
pkg_check_modules(Glib glib-2.0)
include_directories(${GTK_INCLUDE_DIRS} ${Glib_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS} ${Glib_LIBRARY_DIRS})
endif()

foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_SOURCE_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

include_directories(include)

add_executable(wordle ${GUI_TYPE} 
    src/app.c 
    src/guess.c 
    src/input.c 
    src/score.c 
    src/wordles.c 
    src/words.c 
    src/ui/banner.c 
    src/ui/box.c 
    src/ui/color.c 
    src/ui/format.c 
    src/ui/keyboard.c
    src/ui/labels.c 
    src/ui/main.c
    src/ui/rows.c 
    src/ui/window.c
)
if (UNIX OR APPLE)
target_link_libraries(wordle ${GTK_LIBRARIES})
install(FILES ${CMAKE_SOURCE_DIR}/bin/wordle DESTINATION bin)
endif()
if (MSVC)
target_sources(wordle PRIVATE res/wordle.rc)
target_link_libraries(wordle gtk-3 gobject-2.0 gio-2.0 glib-2.0 pango-1.0)
install(FILES ${GTK_DIR}/bin/gtk-3-vs17.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/gdk-3-vs17.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/gobject-2.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/gio-2.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/glib-2.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/gdk_pixbuf-2.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/gmodule-2.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/ffi-7.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/intl-8.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/intl.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/pangocairo-1.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/pango-1.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/pangoft2-1.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/pangowin32-1.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/cairo.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/cairo-gobject.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/fribidi-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/harfbuzz.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/epoxy-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/atk-1.0-0.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/fontconfig-1.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/freetype-6.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/libpng16.dll DESTINATION Wordle)
install(FILES ${GTK_DIR}/bin/expat.dll DESTINATION Wordle)
install(FILES ${CMAKE_SOURCE_DIR}/bin/wordle.exe DESTINATION Wordle)
endif()
