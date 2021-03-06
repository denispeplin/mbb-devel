cmake_minimum_required (VERSION 2.6)
project (mbb C)

if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Debug)
	message (STATUS "set build type to Debug")
endif ()

include (FindPkgConfig)
set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

pkg_check_modules (GLIB REQUIRED glib-2.0>=2.16)
pkg_check_modules (GTHREAD REQUIRED gthread-2.0)

add_definitions (-DNOCOLOR -DNDEBUG)
add_definitions (-Wall -Wextra -Werror -pedantic -std=c99 -D_POSIX_SOURCE)

include_directories (include ${GLIB_INCLUDE_DIRS} ${GTHREAD_INCLUDE_DIRS})
link_directories (${GLIB_LIBRARY_DIRS} ${GTHREAD_LIBRARY_DIRS})

set (MBB_LIBRARIES pthread ${GLIB_LIBRARIES} ${GTHREAD_LIBRARIES})

add_subdirectory (lib)
add_subdirectory (mbbd)
add_subdirectory (mbbsh)
