
## === Library ==================================================================

include_directories (
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

file (GLOB geom_cpp_sources *.cc)

add_library (geom_cpp ${geom_cpp_sources})

## === Test programs ============================================================

## === Language bindings ========================================================

add_subdirectory (bindings)
