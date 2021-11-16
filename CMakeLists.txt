cmake_minimum_required(VERSION 3.16)
project(gui)
set(CMAKE_CXX_STANDARD 11)

include(FindPkgConfig)

######################################################
# setting paths for libraries and executable outputs
######################################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin) 

add_subdirectory(src)
#add_subdirectory(tests)
