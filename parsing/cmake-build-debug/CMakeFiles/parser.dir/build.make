# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gtyene/Cub3D/parsing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gtyene/Cub3D/parsing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/parser.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

CMakeFiles/parser.dir/check.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/check.c.o: ../check.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/parser.dir/check.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/check.c.o -c /Users/gtyene/Cub3D/parsing/check.c

CMakeFiles/parser.dir/check.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/check.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gtyene/Cub3D/parsing/check.c > CMakeFiles/parser.dir/check.c.i

CMakeFiles/parser.dir/check.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/check.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gtyene/Cub3D/parsing/check.c -o CMakeFiles/parser.dir/check.c.s

CMakeFiles/parser.dir/get_text_and_color.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/get_text_and_color.c.o: ../get_text_and_color.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/parser.dir/get_text_and_color.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/get_text_and_color.c.o -c /Users/gtyene/Cub3D/parsing/get_text_and_color.c

CMakeFiles/parser.dir/get_text_and_color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/get_text_and_color.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gtyene/Cub3D/parsing/get_text_and_color.c > CMakeFiles/parser.dir/get_text_and_color.c.i

CMakeFiles/parser.dir/get_text_and_color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/get_text_and_color.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gtyene/Cub3D/parsing/get_text_and_color.c -o CMakeFiles/parser.dir/get_text_and_color.c.s

CMakeFiles/parser.dir/map.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/map.c.o: ../map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/parser.dir/map.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/map.c.o -c /Users/gtyene/Cub3D/parsing/map.c

CMakeFiles/parser.dir/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/map.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gtyene/Cub3D/parsing/map.c > CMakeFiles/parser.dir/map.c.i

CMakeFiles/parser.dir/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/map.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gtyene/Cub3D/parsing/map.c -o CMakeFiles/parser.dir/map.c.s

CMakeFiles/parser.dir/parser.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/parser.c.o: ../parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/parser.dir/parser.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/parser.c.o -c /Users/gtyene/Cub3D/parsing/parser.c

CMakeFiles/parser.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/parser.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gtyene/Cub3D/parsing/parser.c > CMakeFiles/parser.dir/parser.c.i

CMakeFiles/parser.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/parser.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gtyene/Cub3D/parsing/parser.c -o CMakeFiles/parser.dir/parser.c.s

CMakeFiles/parser.dir/player.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/player.c.o: ../player.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/parser.dir/player.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/player.c.o -c /Users/gtyene/Cub3D/parsing/player.c

CMakeFiles/parser.dir/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/player.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gtyene/Cub3D/parsing/player.c > CMakeFiles/parser.dir/player.c.i

CMakeFiles/parser.dir/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/player.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gtyene/Cub3D/parsing/player.c -o CMakeFiles/parser.dir/player.c.s

CMakeFiles/parser.dir/utils.c.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/parser.dir/utils.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/parser.dir/utils.c.o -c /Users/gtyene/Cub3D/parsing/utils.c

CMakeFiles/parser.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/parser.dir/utils.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gtyene/Cub3D/parsing/utils.c > CMakeFiles/parser.dir/utils.c.i

CMakeFiles/parser.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/parser.dir/utils.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gtyene/Cub3D/parsing/utils.c -o CMakeFiles/parser.dir/utils.c.s

# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/check.c.o" \
"CMakeFiles/parser.dir/get_text_and_color.c.o" \
"CMakeFiles/parser.dir/map.c.o" \
"CMakeFiles/parser.dir/parser.c.o" \
"CMakeFiles/parser.dir/player.c.o" \
"CMakeFiles/parser.dir/utils.c.o"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

parser: CMakeFiles/parser.dir/check.c.o
parser: CMakeFiles/parser.dir/get_text_and_color.c.o
parser: CMakeFiles/parser.dir/map.c.o
parser: CMakeFiles/parser.dir/parser.c.o
parser: CMakeFiles/parser.dir/player.c.o
parser: CMakeFiles/parser.dir/utils.c.o
parser: CMakeFiles/parser.dir/build.make
parser: ../../libft/libft.a
parser: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser
.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend:
	cd /Users/gtyene/Cub3D/parsing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gtyene/Cub3D/parsing /Users/gtyene/Cub3D/parsing /Users/gtyene/Cub3D/parsing/cmake-build-debug /Users/gtyene/Cub3D/parsing/cmake-build-debug /Users/gtyene/Cub3D/parsing/cmake-build-debug/CMakeFiles/parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend

