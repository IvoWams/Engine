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
include test/CMakeFiles/os-test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/os-test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/os-test.dir/flags.make

test/CMakeFiles/os-test.dir/os-test.cc.o: test/CMakeFiles/os-test.dir/flags.make
test/CMakeFiles/os-test.dir/os-test.cc.o: test/os-test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/os-test.dir/os-test.cc.o"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/os-test.dir/os-test.cc.o -c /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/os-test.cc

test/CMakeFiles/os-test.dir/os-test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/os-test.dir/os-test.cc.i"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/os-test.cc > CMakeFiles/os-test.dir/os-test.cc.i

test/CMakeFiles/os-test.dir/os-test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/os-test.dir/os-test.cc.s"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/os-test.cc -o CMakeFiles/os-test.dir/os-test.cc.s

# Object files for target os-test
os__test_OBJECTS = \
"CMakeFiles/os-test.dir/os-test.cc.o"

# External object files for target os-test
os__test_EXTERNAL_OBJECTS =

bin/os-test: test/CMakeFiles/os-test.dir/os-test.cc.o
bin/os-test: test/CMakeFiles/os-test.dir/build.make
bin/os-test: test/libtest-main.a
bin/os-test: libfmt.a
bin/os-test: test/gtest/libgtest.a
bin/os-test: test/CMakeFiles/os-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/os-test"
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/os-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/os-test.dir/build: bin/os-test

.PHONY : test/CMakeFiles/os-test.dir/build

test/CMakeFiles/os-test.dir/clean:
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test && $(CMAKE_COMMAND) -P CMakeFiles/os-test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/os-test.dir/clean

test/CMakeFiles/os-test.dir/depend:
	cd /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0 /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0 /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test /home/ivo/projects/private/Engine/engine/lib/fmt-10.2.0/test/CMakeFiles/os-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/os-test.dir/depend

