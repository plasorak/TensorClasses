# find_package(GTest)
# include_directories(${GTEST_INCLUDE_DIRS})

## handling of test executables
## here a generic example for creating one executable per .cpp is shown
file(GLOB tests RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
foreach( sourcefile ${tests} )
  string( REPLACE ".cpp" "" name ${sourcefile} )
  add_executable( ${name} ${sourcefile} )
  target_link_libraries( ${name} tensorutils  ${ROOT_LIBRARIES} ${GTEST_LIBRARIES})
  install(TARGETS ${name} DESTINATION bin)
  add_test(NAME ${name} COMMAND ${name})
endforeach( sourcefile ${tests} )
