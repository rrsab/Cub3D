cmake_minimum_required(VERSION 3.20)
project(Cub3D C)

set(CMAKE_C_STANDARD 99)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/libft/)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/minilibx_mms/)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/inc)


set(CMAKE_C_COMPILER gcc)
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

FILE(GLOB SRC
        parsing/parser.c)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -L ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_opengl/ -framework OpenGL -framework AppKit")
add_executable(Cub3D ${SRC}  parsing/parser.c)

#include_directories(Cub3D ${CMAKE_CURRENT_SOURCE_DIR}/inc/)			# Расположение заголовочных файлов
#target_link_libraries (Cub3D ${CMAKE_CURRENT_SOURCE_DIR}/src/libft/libft.a) # Линковка программы с библиотекой
#target_link_libraries (Cub3D ${CMAKE_CURRENT_SOURCE_DIR}/src/minilibx_opengl/libmlx.a)