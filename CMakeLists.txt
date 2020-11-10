cmake_minimum_required(VERSION 3.5)
project(ImplementationVector VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Test target
# set the include path
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Add the test target
add_executable( run_tests
                test/tests.cpp )
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)

# define C++11 standard
set_property(TARGET run_tests PROPERTY CXX_STANDARD 11)

# The end
