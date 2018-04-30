if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type")
endif()
set(CMAKE_BUILD_TYPE_VALUES "Debug;Release" CACHE INTERNAL "List of supported build")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_BUILD_TYPE_VALUES})

SET(CMAKE_FIND_PACKAGE_SORT_ORDER NATURAL)
SET(CMAKE_FIND_PACKAGE_SORT_DIRECTION DEC)

cmake_minimum_required(VERSION 3.0)
project(example VERSION 0.1.0)

find_package(glez REQUIRED 0.1.0)
find_package(xoverlay REQUIRED)

add_executable(${PROJECT_NAME} example.cpp)

get_target_property(xoverlay_INCLUDE_DIRS xoverlay INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(glez_INCLUDE_DIRS glez INTERFACE_INCLUDE_DIRECTORIES)

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
target_link_libraries(${PROJECT_NAME} glez xoverlay)
target_include_directories(${PROJECT_NAME} PRIVATE "${xoverlay_INCLUDE_DIRS}" "${glez_INCLUDE_DIRS}")