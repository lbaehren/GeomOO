
if (SWIG_FOUND AND RUBY_FOUND)
  set (SWIG_ENABLE_RUBY ON CACHE BOOL "Enable SWIG generated wrapers for Ruby?" FORCE)
else (SWIG_FOUND AND RUBY_FOUND)
  set (SWIG_ENABLE_RUBY OFF CACHE BOOL "Enable SWIG generated wrapers for Ruby?" FORCE)
endif (SWIG_FOUND AND RUBY_FOUND)
