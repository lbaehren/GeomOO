
## ==============================================================================
##
##  Source code documentation
##
##  As there is no tool available which will be able to process all the tested
##  languages, in order to create one common set of documentation, we need to
##  employ
##    - Doxygen, for C/C++, Python
##    - RDoc, for Ruby
##
## ==============================================================================

find_package (Doxygen)

find_program (RDOC_EXECUTABLE rdoc
  HINTS ${RDOC_ROOT_DIR}
  PATH_SUFFIXES bin
  )

## ==============================================================================
##
##  Documentation generation
##
## ==============================================================================

##____________________________________________________________________
##                                                                Ruby

if (RDOC_EXECUTABLE)

  add_custom_target (doc_ruby
    COMMAND ${RDOC_EXECUTABLE} ${PROJECT_SOURCE_DIR}/ruby
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

endif (RDOC_EXECUTABLE)

##____________________________________________________________________
##                                                               C/C++

if (DOXYGEN_EXECUTABLE)

  ## Variables substituted in the Doxygen configuration file

  set (DOXYGEN_PROJECT_NAME     "GeomOO")
  set (DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
  set (DOXYGEN_WARN_LOGFILE     "${CMAKE_CURRENT_BINARY_DIR}/doxygenWarnings.log")
  set (DOXYGEN_IMAGE_PATH       "${CMAKE_CURRENT_SOURCE_DIR}/images")

  ## Configure Doxygen 

  configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    )

endif (DOXYGEN_EXECUTABLE)
