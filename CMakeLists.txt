cmake_minimum_required(VERSION 3.0.0)
project(basic_algos_ds VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

include_directories(include/datastructures)

add_executable(all_tests 
    test/test_main.cpp
    test/queue_test.cpp)
target_link_libraries(all_tests gtest)
gtest_discover_tests(all_tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
