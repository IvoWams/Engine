# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0

# Include any dependencies generated for this target.
include test/CMakeFiles/test-main.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test-main.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test-main.dir/flags.make

test/CMakeFiles/test-main.dir/test-main.cc.o: test/CMakeFiles/test-main.dir/flags.make
test/CMakeFiles/test-main.dir/test-main.cc.o: test/test-main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test-main.dir/test-main.cc.o"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-main.dir/test-main.cc.o -c /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/test-main.cc

test/CMakeFiles/test-main.dir/test-main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-main.dir/test-main.cc.i"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/test-main.cc > CMakeFiles/test-main.dir/test-main.cc.i

test/CMakeFiles/test-main.dir/test-main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-main.dir/test-main.cc.s"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/test-main.cc -o CMakeFiles/test-main.dir/test-main.cc.s

test/CMakeFiles/test-main.dir/gtest-extra.cc.o: test/CMakeFiles/test-main.dir/flags.make
test/CMakeFiles/test-main.dir/gtest-extra.cc.o: test/gtest-extra.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/test-main.dir/gtest-extra.cc.o"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-main.dir/gtest-extra.cc.o -c /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/gtest-extra.cc

test/CMakeFiles/test-main.dir/gtest-extra.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-main.dir/gtest-extra.cc.i"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/gtest-extra.cc > CMakeFiles/test-main.dir/gtest-extra.cc.i

test/CMakeFiles/test-main.dir/gtest-extra.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-main.dir/gtest-extra.cc.s"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/gtest-extra.cc -o CMakeFiles/test-main.dir/gtest-extra.cc.s

test/CMakeFiles/test-main.dir/util.cc.o: test/CMakeFiles/test-main.dir/flags.make
test/CMakeFiles/test-main.dir/util.cc.o: test/util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/test-main.dir/util.cc.o"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-main.dir/util.cc.o -c /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/util.cc

test/CMakeFiles/test-main.dir/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-main.dir/util.cc.i"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/util.cc > CMakeFiles/test-main.dir/util.cc.i

test/CMakeFiles/test-main.dir/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-main.dir/util.cc.s"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/util.cc -o CMakeFiles/test-main.dir/util.cc.s

# Object files for target test-main
test__main_OBJECTS = \
"CMakeFiles/test-main.dir/test-main.cc.o" \
"CMakeFiles/test-main.dir/gtest-extra.cc.o" \
"CMakeFiles/test-main.dir/util.cc.o"

# External object files for target test-main
test__main_EXTERNAL_OBJECTS =

test/libtest-main.a: test/CMakeFiles/test-main.dir/test-main.cc.o
test/libtest-main.a: test/CMakeFiles/test-main.dir/gtest-extra.cc.o
test/libtest-main.a: test/CMakeFiles/test-main.dir/util.cc.o
test/libtest-main.a: test/CMakeFiles/test-main.dir/build.make
test/libtest-main.a: test/CMakeFiles/test-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libtest-main.a"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && $(CMAKE_COMMAND) -P CMakeFiles/test-main.dir/cmake_clean_target.cmake
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test-main.dir/build: test/libtest-main.a

.PHONY : test/CMakeFiles/test-main.dir/build

test/CMakeFiles/test-main.dir/clean:
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && $(CMAKE_COMMAND) -P CMakeFiles/test-main.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test-main.dir/clean

test/CMakeFiles/test-main.dir/depend:
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0 /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0 /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/CMakeFiles/test-main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test-main.dir/depend

