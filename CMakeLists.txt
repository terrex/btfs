cmake_policy(SET CMP0048 NEW)
project(btfs VERSION 2.13)
cmake_minimum_required(VERSION 3.1)

add_subdirectory(src)
add_subdirectory(scripts)
add_subdirectory(man)


########### install files ###############




#original Makefile.am contents follow:

#AUTOMAKE_OPTIONS = foreign
#SUBDIRS = src scripts man
#EXTRA_DIST = LICENSE README.md
