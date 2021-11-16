
################################
# setting path to include files 
################################

include_directories( 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

include(FindPkgConfig)

pkg_check_modules(gtk REQUIRED gtk+-3.0)

message(STATUS "gtk libraries: ${gtk_LIBRARIES}")
message(STATUS "gtk compiler flags: ${gtk_CFLAGS}")
message(STATUS "gtk lib paths: ${gtk_LIBRARY_DIRS}")
message(STATUS "gtk linker flags: ${gtk_LDFLAGS}")


######################
# compiled libraries
######################

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

message(STATUS "${CMAKE_SOURCE_DIR}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}")


add_executable(main main.c)
target_compile_options(main PUBLIC ${gtk_CFLAGS})
target_link_libraries(main ${gtk_LDFLAGS})
target_link_options(main BEFORE PUBLIC "-pthread;-rdynamic")

# THIS DID NOT WORK ##########################################
#list(APPEND CMAKE_MODULE_PATH "/usr/lib/x86_64-linux-gnu")
#pkg_search_module(gtk gtk+-3.0 REQUIRED)
#message(STATUS "${gtk_MODULE_NAME}")
#target_include_directories(main PUBLIC ${gtk_INCLUDE_DIRS})
#target_link_libraries( main ${gtk_LIBRARIES})
###############################################################
