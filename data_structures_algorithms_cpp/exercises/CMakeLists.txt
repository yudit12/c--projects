# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# Project name
project(data_structures_algorithms_cpp)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ensure debugging symbols are included
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Add AddressSanitizer flags for Debug builds
if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Building with AddressSanitizer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
endif()

# Add a static library for LinkedList
add_library(LinkedList STATIC 01-BigO/LinkedList.cpp)

# Ensure the main.cpp exists
if(EXISTS "${CMAKE_SOURCE_DIR}/01-BigO/main.cpp")
    # Add the executable target for the main application
    add_executable(data_structures_algorithms_cpp 01-BigO/main.cpp)
    
    # Link the static library to the main executable
    target_link_libraries(data_structures_algorithms_cpp LinkedList)
else()
    message(FATAL_ERROR "01-BigO/main.cpp not found!")
endif()

# Install GTest if it's not found
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
if(EXISTS "${CMAKE_SOURCE_DIR}/tests/LinkedListTest.cpp")
    # Add the test executable
    add_executable(LinkedListTest tests/LinkedListTest.cpp)

    # Include the directory containing LinkedList.h for the test executable
    target_include_directories(LinkedListTest PRIVATE 01-BigO)

    # Link the static library to the test executable
    target_link_libraries(LinkedListTest LinkedList)

    # Link GTest to the test executable
    target_link_libraries(LinkedListTest GTest::GTest GTest::Main)

    # # Apply sanitizer flags to LinkedListTest
    # target_compile_options(LinkedListTest PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    # target_link_options(LinkedListTest PRIVATE -fsanitize=address)

else()
    message(FATAL_ERROR "tests/LinkedListTest.cpp not found!")
endif()


# Enable testing
enable_testing()

# Add the test to CTest
add_test(NAME LinkedListTest COMMAND LinkedListTest)

# # Output build type and sanitization status
# message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
# message(STATUS "AddressSanitizer: ENABLED")