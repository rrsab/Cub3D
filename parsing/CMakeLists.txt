cmake_minimum_required(VERSION 3.20)

project(parser)

set (CMAKE_C_STANDARD 99)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -O2")

set (CMAKE_C_COMPILER gcc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libft/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../maps/)

file (GLOB
        SOURCES "*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/../libft/libft.a)