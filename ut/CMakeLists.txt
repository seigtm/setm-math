# Unit tests sources.
set(SOURCES 
    complex_tests.cpp
    polynomial_tests.cpp
    polycomplex_tests.cpp
)
# Creating tests executable.
add_executable(tests ${SOURCES})
target_link_libraries(tests PRIVATE CONAN_PKG::gtest)

# Adding CTest.
add_test(NAME GTest COMMAND run_tests)
# Coverage.
if(COVERAGE)
    setup_target_for_coverage_gcovr_html(NAME testCov EXECUTABLE tests)
endif()
