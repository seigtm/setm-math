cmake_minimum_required(VERSION 3.5)
project(SetmMathTest VERSION 2.0.0)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(SetmMathTest 
    main.cpp
    ut/complex_tests.cpp
    ut/polynomial_tests.cpp
    ut/polycomplex_tests.cpp
)
target_link_libraries(SetmMathTest PRIVATE 
    CONAN_PKG::SetmMath
    CONAN_PKG::gtest
)
