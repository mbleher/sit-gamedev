cmake_minimum_required ( VERSION 2.6 )

# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

project ( Game )
add_executable ( Game game.m.cpp )
target_link_libraries ( Game ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest.a ${CMAKE_CURRENT_SOURCE_DIR}/libs/libgtest_main.a pthread ) 