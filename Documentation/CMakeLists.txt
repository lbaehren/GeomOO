
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
##  System inspection
##
## ==============================================================================

