
## ==============================================================================
##
##  Wrapper to generate bingings to Ruby
##
## ==============================================================================

##__________________________________________________________
## Check conditions for generating bindings

if (SWIG_FOUND AND RUBY_FOUND)
  set (SWIG_ENABLE_RUBY ON CACHE BOOL "Enable SWIG generated wrapper for Ruby?" FORCE)
else (SWIG_FOUND AND RUBY_FOUND)
  set (SWIG_ENABLE_RUBY OFF CACHE BOOL "Enable SWIG generated wrapper for Ruby?" FORCE)
endif (SWIG_FOUND AND RUBY_FOUND)

##__________________________________________________________
## Generate bindings

if (SWIG_ENABLE_RUBY)
endif (SWIG_ENABLE_RUBY)
