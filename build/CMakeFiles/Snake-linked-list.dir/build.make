# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sibjor/Projects/snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sibjor/Projects/snake/build

# Include any dependencies generated for this target.
include CMakeFiles/Snake-linked-list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Snake-linked-list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Snake-linked-list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Snake-linked-list.dir/flags.make

CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o: CMakeFiles/Snake-linked-list.dir/flags.make
CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o: /home/sibjor/Projects/snake/snake-linked-list.c
CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o: CMakeFiles/Snake-linked-list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/sibjor/Projects/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o -MF CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o.d -o CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o -c /home/sibjor/Projects/snake/snake-linked-list.c

CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sibjor/Projects/snake/snake-linked-list.c > CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.i

CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sibjor/Projects/snake/snake-linked-list.c -o CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.s

# Object files for target Snake-linked-list
Snake__linked__list_OBJECTS = \
"CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o"

# External object files for target Snake-linked-list
Snake__linked__list_EXTERNAL_OBJECTS =

Snake-linked-list: CMakeFiles/Snake-linked-list.dir/snake-linked-list.c.o
Snake-linked-list: CMakeFiles/Snake-linked-list.dir/build.make
Snake-linked-list: _deps/raylib-build/raylib/libraylib.a
Snake-linked-list: /usr/lib/x86_64-linux-gnu/libGL.so
Snake-linked-list: /usr/lib/x86_64-linux-gnu/libGLU.so
Snake-linked-list: _deps/raylib-build/raylib/external/glfw/src/libglfw3.a
Snake-linked-list: /usr/lib/x86_64-linux-gnu/librt.a
Snake-linked-list: /usr/lib/x86_64-linux-gnu/libm.so
Snake-linked-list: CMakeFiles/Snake-linked-list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/sibjor/Projects/snake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Snake-linked-list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Snake-linked-list.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copying compile_commands.json to project root"
	/usr/bin/cmake -E copy /home/sibjor/Projects/snake/build/compile_commands.json /home/sibjor/Projects/snake/compile_commands.json

# Rule to build all files generated by this target.
CMakeFiles/Snake-linked-list.dir/build: Snake-linked-list
.PHONY : CMakeFiles/Snake-linked-list.dir/build

CMakeFiles/Snake-linked-list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Snake-linked-list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Snake-linked-list.dir/clean

CMakeFiles/Snake-linked-list.dir/depend:
	cd /home/sibjor/Projects/snake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sibjor/Projects/snake /home/sibjor/Projects/snake /home/sibjor/Projects/snake/build /home/sibjor/Projects/snake/build /home/sibjor/Projects/snake/build/CMakeFiles/Snake-linked-list.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Snake-linked-list.dir/depend

