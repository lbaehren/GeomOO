
# Include paths for header files
include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/geom_cpp
    )

# Subdirectories
add_subdirectory (libs)
add_subdirectory (apps)
add_subdirectory (tests)
