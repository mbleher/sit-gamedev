project ( Game )

cmake_minimum_required ( VERSION 2.6 )

file( GLOB_RECURSE CPPFILES src/*.cpp )

add_executable ( Game game.m.cpp ${CPPFILES})
target_link_libraries ( Game ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest.a ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest_main.a pthread )