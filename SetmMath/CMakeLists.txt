cmake_minimum_required(VERSION 3.5)
project(SetmMath VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(HEADERS
    include/setmexport.h
    include/math/complex.hpp
    include/math/polynomial.hpp
)
install(DIRECTORY include/ DESTINATION include/setm)

set(SOURCES
    src/complex/complex.cpp
)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_compile_definitions(${PROJECT_NAME} PRIVATE SETM_EXPORTING=1)
target_link_libraries(${PROJECT_NAME} PRIVATE CONAN_PKG::boost)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
