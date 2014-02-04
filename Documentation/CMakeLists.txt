#--------------------------------------------------------------------------------
# Copyright (c) 2012-2014, Lars Baehren <lbaehren@gmail.com>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
#  * Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#--------------------------------------------------------------------------------

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

add_custom_target (doc ALL)

##____________________________________________________________________
##                                                                Ruby

if (YARD_EXECUTABLE)

    add_custom_target (run_yard
      COMMAND ${YARD_EXECUTABLE} -o ${CMAKE_CURRENT_BINARY_DIR}/doc ${PROJECT_SOURCE_DIR}/ruby
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating documentation for Ruby code"
      )

    add_dependencies (doc run_yard)

else (YARD_EXECUTABLE)

  if (RDOC_EXECUTABLE)

    add_custom_target (run_rdoc
      COMMAND ${RDOC_EXECUTABLE} --force-update --diagram ${PROJECT_SOURCE_DIR}/ruby
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating documentation for Ruby code"
      )

    add_dependencies (doc run_rdoc)

  endif (RDOC_EXECUTABLE)

endif (YARD_EXECUTABLE)

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

  add_custom_target (run_doxygen
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating documentation for C++ code"
    )

  add_dependencies (doc run_doxygen)

endif (DOXYGEN_EXECUTABLE)
