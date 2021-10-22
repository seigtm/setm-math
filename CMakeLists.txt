cmake_minimum_required(VERSION 3.5)
project(SetmMathTest VERSION 1.0.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(SetmMathTest main.cpp)
target_link_libraries(SetmMathTest PUBLIC CONAN_PKG::SetmMath)
target_include_directories(SetmMathTest PUBLIC ${CMAKE_CURRENT_LIST_DIR})
