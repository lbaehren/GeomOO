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

option (ENABLE_TESTING    "Enable testing framework?"                  YES )

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

## ==============================================================================
##
##  Project sub-directories
##
## ==============================================================================

add_subdirectory (cpp)
