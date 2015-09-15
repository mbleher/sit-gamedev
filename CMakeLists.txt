project ( Game )

cmake_minimum_required ( VERSION 2.6 )

file( GLOB_RECURSE CPPFILES src/*.cpp )
file( GLOB_RECURSE TESTFILES test/*.cpp )

include_directories(
  ${PROJECT_SOURCE_DIR}/src/engine/memory
  ${PROJECT_SOURCE_DIR}/src/engine/containers
  )

add_executable ( Game game.m.cpp ${CPPFILES} )
add_executable ( runTests test/test.m.cpp ${CPPFILES} ${TESTFILES} )
target_link_libraries ( runTests ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest.a ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest_main.a pthread )