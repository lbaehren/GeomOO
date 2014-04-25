## -----------------------------------------------------------------------------
## Test programs

enable_testing()

set (tests
  circles
  tCircle
  tSphere
  tCylinder
  tCone
#  tConeSegment
  )

foreach (test ${tests})
  ## compiler instructions
  add_executable (${test} ${test}.cc)
  ## linker instructions
  target_link_libraries (${test} geometry)
  ## register test program
  add_test (${test} ${test})
endforeach (test)


