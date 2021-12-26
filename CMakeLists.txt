cmake_minimum_required(VERSION 3.20)

project(cub3D)

set (CMAKE_C_STANDARD 99)

#set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -O2")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D DARWIN=1 -L ${CMAKE_CURRENT_SOURCE_DIR}/minilibx/minilibx_opengl/ -framework OpenGL -framework AppKit")

set (CMAKE_C_COMPILER gcc)

include_directories(libft)
include_directories(includes)
include_directories(maps)
include_directories(minilibx/minilibx_opengl)
include_directories(minilibx)

file (GLOB SOURCES
        "sources/*.c"
        "sources/parser/*.c"
        "sources/rendering/*.c"
        "sources/events/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

message(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
        ${CMAKE_CURRENT_SOURCE_DIR}/minilibx/minilibx_opengl/libmlx.a)