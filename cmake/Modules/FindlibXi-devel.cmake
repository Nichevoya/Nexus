if (NOT libXi_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    libXi-devel URL https://www.x.org/releases/individual/lib/libXi-1.8.tar.gz )
    FetchContent_GetProperties(libXi-devel)
    if (NOT libXi-devel_POPULATED)
            set(FETCHCONTENT_QUIET NO)
            FetchContent_Populate(libXi-devel)
            set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
            add_subdirectory(${libXi_SOURCE_DIR} ${libXi_BINARY_DIR})
  endif()
endif()