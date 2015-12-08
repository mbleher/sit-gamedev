project ( Game )

cmake_minimum_required ( VERSION 2.6 )

file( GLOB_RECURSE CPPFILES src/*.cpp )
file( GLOB_RECURSE TESTFILES test/*.cpp )

enable_language( C CXX )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set( CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/_builds/CMakeModules"
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  )

find_package( SFML 2.1.0 REQUIRED system window graphics network audio )

include_directories(
  ${PROJECT_SOURCE_DIR}/src/engine/memory
  ${PROJECT_SOURCE_DIR}/src/engine/containers
  ${PROJECT_SOURCE_DIR}/src/engine/data
  ${PROJECT_SOURCE_DIR}/src/engine/scene
  ${PROJECT_SOURCE_DIR}/src/engine/input
  ${PROJECT_SOURCE_DIR}/src/engine/rendering
  ${PROJECT_SOURCE_DIR}/src/engine/events
  ${PROJECT_SOURCE_DIR}/src/engine/factories
  ${PROJECT_SOURCE_DIR}/src/game/controllers
  ${PROJECT_SOURCE_DIR}/external/googletest/googletest
  ${PROJECT_SOURCE_DIR}/external/googletest/googletest/include
  ${SFML_INCLUDE_DIR}
  )

add_custom_target(
  git_update
  COMMAND git submodule init
  COMMAND git submodule update
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  )

add_library(
  gtest
  ${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest-all.cc
  ${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest_main.cc
  )

add_dependencies( gtest git_update )

set_source_files_properties(${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest-all.cc PROPERTIES GENERATED 1)
set_source_files_properties(${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest_main.cc PROPERTIES GENERATED 1)

add_executable ( Game game.m.cpp ${CPPFILES} )
add_executable ( runTests test/test.m.cpp ${CPPFILES} ${TESTFILES} )

add_dependencies( runTests gtest )

target_link_libraries(
  Game
  ${SFML_LIBRARIES}
  )

target_link_libraries(
  runTests
  gtest
  pthread
  ${SFML_LIBRARIES}
  )