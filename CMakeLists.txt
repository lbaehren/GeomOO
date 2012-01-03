## ==============================================================================
##
##  CMake project settings
##
## ==============================================================================

## Name of the project handled by CMake
project (GeomOO)

## Minimum required version of CMake to configure the project
cmake_minimum_required (VERSION 2.8)

## Enforced CMake policy
cmake_policy (VERSION 2.8)

## Project release version (major.minor.patch)
set (GeomOO_VERSION_MAJOR 0 )
set (GeomOO_VERSION_MINOR 1 )
set (GeomOO_VERSION_PATCH 0 )
set (GeomOO_VERSION "${GeomOO_VERSION_MAJOR}.${GeomOO_VERSION_MINOR}.${GeomOO_VERSION_PATCH}")

## ==============================================================================
##
##  Configuration/Build options
##
## ==============================================================================

option (ENABLE_DOCUMENTATION "Enable generation of documentation?"        YES )
option (ENABLE_TESTING       "Enable testing framework?"                  YES )
option (SWIG_ENABLE_PYTHON   "Enable SWIG generated wrapper for Python?"  YES )
option (SWIG_ENABLE_RUBY     "Enable SWIG generated wrapper for Ruby?"    YES )

##__________________________________________________________
## Handle option: Enable testing framework?

if (ENABLE_TESTING)
  include (CTest)
  enable_testing()
endif (ENABLE_TESTING)

## ==============================================================================
##
##  System inspection
##
## ==============================================================================

find_package (PythonInterp)
find_package (PythonLibs)
find_package (Ruby)
find_package (SWIG)

## ==============================================================================
##
##  Project sub-directories
##
## ==============================================================================

add_subdirectory (cpp)
add_subdirectory (python)
add_subdirectory (ruby)

if (ENABLE_DOCUMENTATION)
  add_subdirectory (Documentation)
endif (ENABLE_DOCUMENTATION)

## ==============================================================================
##
##  Configuration summary
##
## ==============================================================================

message (STATUS "------------------------------------------------------------"  )
message (STATUS "[PulsarTools] Configuration summary."                          )
message (STATUS "------------------------------------------------------------ " )
message (STATUS " System configuration:"                                        )
message (STATUS " .. Processor type ............. = ${CMAKE_SYSTEM_PROCESSOR}"  )
message (STATUS " .. CMake executable ........... = ${CMAKE_COMMAND}"           )
message (STATUS " .. CMake version .............. = ${CMAKE_VERSION}"           )
message (STATUS " .. System name ................ = ${CMAKE_SYSTEM}"            )
message (STATUS " .. C++ compiler ............... = ${CMAKE_CXX_COMPILER}"      )
message (STATUS " .. C compiler ................. = ${CMAKE_C_COMPILER}"        )
message (STATUS " .. size(void*) ................ = ${CMAKE_SIZEOF_VOID_P}"     )
message (STATUS " Python support:"                                              )
message (STATUS " .. Python interpreter ......... = ${PYTHON_EXECUTABLE}"       )
message (STATUS " .. Python version ............. = ${PYTHON_VERSION_STRING}"   )
message (STATUS " .. Python include directories . = ${PYTHON_INCLUDE_DIRS}"     )
message (STATUS " .. Python libraries ........... = ${PYTHON_LIBRARIES}"        )
message (STATUS " Ruby support:"                                                )
message (STATUS " .. Ruby executable ............ = ${RUBY_EXECUTABLE}"         )
message (STATUS " .. Ruby version ............... = ${RUBY_VERSION}"            )
message (STATUS " .. Ruby include directories ... = ${RUBY_INCLUDE_DIRS}"       )
message (STATUS " .. Ruby library ............... = ${RUBY_LIBRARY}"            )
message (STATUS " SWIG wrapper generation:"                                     )
message (STATUS " .. SWIG executable ............ = ${SWIG_EXECUTABLE}"         )
message (STATUS " .. SWIG version ............... = ${SWIG_VERSION}"            )
message (STATUS " .. Enable wrapper for Python .. = ${SWIG_ENABLE_PYTHON}"      )
message (STATUS " .. Enable wrapper for Ruby .... = ${SWIG_ENABLE_RUBY}"        )
message (STATUS " Generation of documentation:"                                 )
message (STATUS " .. Doxygen .................... = ${DOXYGEN_EXECUTABLE}"      )
message (STATUS " .. RDoc ....................... = ${RDOC_EXECUTABLE}"         )
message (STATUS "------------------------------------------------------------ " )
