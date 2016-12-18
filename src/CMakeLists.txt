find_package(PkgConfig REQUIRED)
pkg_search_module(FUSE REQUIRED fuse>=2.8.0)
pkg_search_module(LIBTORRENT REQUIRED libtorrent-rasterbar>=0.16.0)
pkg_search_module(LIBCURL REQUIRED libcurl>=7.22.0)

########### next target ###############

SET(btfs_SRCS
   btfs.cc
   btfs.h
)

link_directories(${FUSE_LIBRARY_DIRS} ${LIBTORRENT_LIBRARY_DIRS} ${LIBCURL_LIBRARY_DIRS})

add_executable(btfs ${btfs_SRCS})

target_include_directories(btfs PUBLIC ${FUSE_INCLUDE_DIRS} ${LIBTORRENT_INCLUDE_DIRS} ${LIBCURL_INCLUDE_DIRS})
target_compile_options(btfs PUBLIC -DVERSION="${PROJECT_VERSION}" -DPACKAGE="${PROJECT_NAME}" -Wall -Wextra -Wconversion -Wsign-compare -Wsign-conversion -Wno-unused-parameter  ${FUSE_CFLAGS_OTHER} ${LIBTORRENT_CFLAGS_OTHER} ${LIBCURL_CFLAGS_OTHER} ${FUSE_CFLAGS} ${LIBTORRENT_CFLAGS} ${LIBCURL_CFLAGS})
target_link_libraries(btfs ${FUSE_LIBRARIES} ${LIBTORRENT_LIBRARIES} ${LIBCURL_LIBRARIES})

install(TARGETS btfs DESTINATION bin)


########### install files ###############




#original Makefile.am contents follow:

#bin_PROGRAMS = btfs
#btfs_SOURCES = btfs.cc btfs.h
#btfs_CPPFLAGS = -Wall -Wextra -Wconversion -Wsign-compare -Wsign-conversion -Wno-unused-parameter $(FUSE_CFLAGS) $(LIBTORRENT_CFLAGS) $(LIBCURL_CFLAGS)
#btfs_LDADD = $(FUSE_LIBS) $(LIBTORRENT_LIBS) $(LIBCURL_LIBS)
