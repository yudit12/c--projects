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

# Set custom output directories for executables and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bins)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Library and include directory mappings
set(LIBRARY_INCLUDE_MAPPING
    LinkedList:${CMAKE_SOURCE_DIR}/LinkedLists
    DoublyLinkedList:${CMAKE_SOURCE_DIR}/DoublyLinkedLists
)

# Create static libraries and add them to the project
foreach(mapping IN LISTS LIBRARY_INCLUDE_MAPPING)
    string(REPLACE ":" ";" pair ${mapping})
    list(GET pair 0 library_name)
    list(GET pair 1 include_dir)

    # Add the library source file
    add_library(${library_name} STATIC ${include_dir}/${library_name}.cpp)

    # Add the include directory for this library
    target_include_directories(${library_name} PUBLIC ${include_dir})
endforeach()

# Define a list of modules and their corresponding directories
set(MODULES
    "DoublyLinkedList"
    "LinkedList"
    # Add more modules here as needed
)

# Iterate over each module and process its main.cpp if it exists
foreach(MODULE_NAME ${MODULES})
    set(MODULE_MAIN_CPP "${CMAKE_SOURCE_DIR}/${MODULE_NAME}s/main.cpp")
    
    # Check if the main.cpp exists for the module
    if(EXISTS ${MODULE_MAIN_CPP})
        # Add the executable target for this module's main
        add_executable(${MODULE_NAME}_main ${MODULE_MAIN_CPP})
        
        # Link the module's static library to this new executable
        # Ensure that the library is linked using the full path
        target_link_libraries(${MODULE_NAME}_main ${CMAKE_BINARY_DIR}/lib/lib${MODULE_NAME}.a)
        
        # Add the corresponding include directory for the new executable
        target_include_directories(${MODULE_NAME}_main PUBLIC ${CMAKE_SOURCE_DIR}/${MODULE_NAME})

        # Set the output directory for the new executable under build/bins/<module>
        set_target_properties(${MODULE_NAME}_main PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bins/${MODULE_NAME})
    else()
        message(FATAL_ERROR "${MODULE_MAIN_CPP} not found!")
    endif()
endforeach()

# Ensure the main.cpp exists - app main
if(EXISTS "${CMAKE_SOURCE_DIR}/main.cpp")
    # Add the executable target for the main application
    add_executable(data_structures_algorithms_cpp main.cpp)
    
    # Link all static libraries to the main executable
    foreach(mapping IN LISTS LIBRARY_INCLUDE_MAPPING)
        string(REPLACE ":" ";" pair ${mapping})
        list(GET pair 0 library_name)
        target_link_libraries(data_structures_algorithms_cpp ${library_name})
    endforeach()
else()
    message(FATAL_ERROR "data_structures_algorithms_cpp/main.cpp not found!")
endif()

# Define a mapping of test names to their required libraries
set(TEST_LIBRARY_MAPPING
    LinkedListTest:LinkedList
    DoublyLinkedListTest:DoublyLinkedList
    # Add more mappings as needed
)

# Add all test executables for .cpp files in the tests folder
file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

# Set the custom output directory for test executables
set(TEST_EXECUTABLE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bins/tests)

foreach(source_file ${TEST_SOURCES})
    # Extract the base name of the file without extension
    get_filename_component(test_name ${source_file} NAME_WE)

    # Add an executable for each test file
    add_executable(${test_name} ${source_file})

    # Link GTest to the test executable
    target_link_libraries(${test_name} GTest::GTest GTest::Main)

    # Dynamically link the correct library and include directories
    foreach(mapping IN LISTS TEST_LIBRARY_MAPPING)
        string(REPLACE ":" ";" pair ${mapping})
        list(GET pair 0 mapped_name)
        list(GET pair 1 library)

        if("${test_name}" STREQUAL "${mapped_name}")
            # Link the appropriate library
            target_link_libraries(${test_name} ${library})

            # Add the corresponding include directory
            foreach(include_mapping IN LISTS LIBRARY_INCLUDE_MAPPING)
                string(REPLACE ":" ";" include_pair ${include_mapping})
                list(GET include_pair 0 include_library)
                list(GET include_pair 1 include_directory)

                if("${library}" STREQUAL "${include_library}")
                    target_include_directories(${test_name} PRIVATE ${include_directory})
                endif()
            endforeach()
        endif()
    endforeach()

    # Add the test to CTest
    add_test(NAME ${test_name} COMMAND ${test_name})

    # Set the output directory for test executables under build/bins/test
    set_target_properties(${test_name} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${TEST_EXECUTABLE_OUTPUT_DIRECTORY})
endforeach()

# Install GTest if it's not found
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Enable testing
enable_testing()

# Map parent directories to their corresponding library targets
set(DIRECTORY_LIBRARY_MAPPING
    "${CMAKE_SOURCE_DIR}/LinkedLists:LinkedList"
    "${CMAKE_SOURCE_DIR}/DoublyLinkedLists:DoublyLinkedList"
)

# Iterate over each parent directory - create executables for the QUESTION *.cpp files
foreach(mapping IN LISTS DIRECTORY_LIBRARY_MAPPING)
    # Split "Directory:Library" mapping into components
    string(REPLACE ":" ";" pair ${mapping})
    list(GET pair 0 parent_dir)
    list(GET pair 1 library_name)

    # Check if the QUESTION subdirectory exists
    if(EXISTS "${parent_dir}/QUESTION")
        # Glob all .cpp files in the QUESTION subdirectory
        file(GLOB QUESTION_SOURCES "${parent_dir}/QUESTION/*.cpp")

        foreach(source_file ${QUESTION_SOURCES})
            # Extract the base name of the file without extension
            get_filename_component(executable_name ${source_file} NAME_WE)

            # Add an executable for each .cpp file
            add_executable(${executable_name} ${source_file})

            # Link the corresponding library to the executable
            target_link_libraries(${executable_name} ${library_name})

            # Set the output directory for the executables under build/bins
            set_target_properties(${executable_name} PROPERTIES 
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bins/${library_name}/QUESTION")
        endforeach()
    endif()
endforeach()

# Output build type and sanitization status
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "AddressSanitizer: ENABLED (if Debug)")
