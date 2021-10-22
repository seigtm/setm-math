cmake_minimum_required(VERSION 3.5)
project(SetmMath VERSION 0.1.0 LANGUAGES CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(root ${PROJECT_SOURCE_DIR})
set(bin ${root}/bin)

set(libs_names complex polynomial)
set(components complex)

foreach(comp ${components})
    list(APPEND sources ${root}/src/${comp}/${comp}.cpp)
endforeach()

set(directories
    ${root}/include
    ${root}/include/math
)

add_library(${PROJECT_NAME} SHARED ${sources})
target_compile_definitions(${PROJECT_NAME} PRIVATE SETM_EXPORTING=1)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${directories}
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
target_link_libraries(${PROJECT_NAME} PRIVATE CONAN_PKG::boost)


macro(add_copy file destination)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${file} ${destination})
endmacro()

file(GLOB_RECURSE headers ${root}/include/*.hpp ${root}/include/*.h)
list(REMOVE_DUPLICATES headers)

foreach(header ${headers})
    string(REPLACE "${root}" "" header_name ${header})
    get_filename_component(header_path "${bin}${header_name}" DIRECTORY)
    make_directory("${header_path}/")
    add_copy(${header} ${bin}${header_name})
endforeach()

set(lib_dir ${bin}/lib/${CMAKE_BUILD_TYPE}/)
make_directory(${lib_dir})

if(WIN32)
    if(MSVC)
        set(lib_name ${PROJECT_NAME}.lib)
        add_copy(${root}/build/${CMAKE_BUILD_TYPE}/${lib_name} ${lib_dir}/${lib_name})
    else()
        set(lib_name lib${PROJECT_NAME}.dll)
        add_copy(${root}/build/${lib_name} ${lib_dir}/${lib_name})
    endif()
else()
    set(lib_name lib${PROJECT_NAME}.so)
endif()

# add_copy(${root}/build/${lib_name} ${lib_dir}/${lib_name})

macro(add_header_file lib_name)
    file(WRITE ${bin}/include/${lib_name} "#pragma once\n#include <math/${lib_name}.hpp>\n")
endmacro()

foreach(lib ${libs_names})
    add_header_file(${lib})
endforeach()
