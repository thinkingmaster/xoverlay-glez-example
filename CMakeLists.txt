cmake_minimum_required(VERSION 3.0)
project(example LANGUAGES C VERSION 0.0.1)

find_package(glez REQUIRED)
find_package(xoverlay REQUIRED)

add_executable(${PROJECT_NAME} example.c)

get_target_property(xoverlay_INCLUDE_DIRS xoverlay INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(glez_INCLUDE_DIRS glez INTERFACE_INCLUDE_DIRECTORIES)

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
target_link_libraries(${PROJECT_NAME} glez xoverlay)
target_include_directories(${PROJECT_NAME} PRIVATE "${xoverlay_INCLUDE_DIRS}" "${glez_INCLUDE_DIRS}")