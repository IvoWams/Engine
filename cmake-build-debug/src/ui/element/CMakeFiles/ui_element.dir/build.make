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
CMAKE_SOURCE_DIR = /home/ivo/projects/private/Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivo/projects/private/Engine/cmake-build-debug

# Include any dependencies generated for this target.
include src/ui/element/CMakeFiles/ui_element.dir/depend.make

# Include the progress variables for this target.
include src/ui/element/CMakeFiles/ui_element.dir/progress.make

# Include the compile flags for this target's objects.
include src/ui/element/CMakeFiles/ui_element.dir/flags.make

src/ui/element/CMakeFiles/ui_element.dir/Element.cpp.o: src/ui/element/CMakeFiles/ui_element.dir/flags.make
src/ui/element/CMakeFiles/ui_element.dir/Element.cpp.o: ../src/ui/element/Element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivo/projects/private/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/ui/element/CMakeFiles/ui_element.dir/Element.cpp.o"
	cd /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ui_element.dir/Element.cpp.o -c /home/ivo/projects/private/Engine/src/ui/element/Element.cpp

src/ui/element/CMakeFiles/ui_element.dir/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ui_element.dir/Element.cpp.i"
	cd /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivo/projects/private/Engine/src/ui/element/Element.cpp > CMakeFiles/ui_element.dir/Element.cpp.i

src/ui/element/CMakeFiles/ui_element.dir/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ui_element.dir/Element.cpp.s"
	cd /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivo/projects/private/Engine/src/ui/element/Element.cpp -o CMakeFiles/ui_element.dir/Element.cpp.s

# Object files for target ui_element
ui_element_OBJECTS = \
"CMakeFiles/ui_element.dir/Element.cpp.o"

# External object files for target ui_element
ui_element_EXTERNAL_OBJECTS =

src/ui/element/libui_element.a: src/ui/element/CMakeFiles/ui_element.dir/Element.cpp.o
src/ui/element/libui_element.a: src/ui/element/CMakeFiles/ui_element.dir/build.make
src/ui/element/libui_element.a: src/ui/element/CMakeFiles/ui_element.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivo/projects/private/Engine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libui_element.a"
	cd /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element && $(CMAKE_COMMAND) -P CMakeFiles/ui_element.dir/cmake_clean_target.cmake
	cd /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ui_element.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/ui/element/CMakeFiles/ui_element.dir/build: src/ui/element/libui_element.a

.PHONY : src/ui/element/CMakeFiles/ui_element.dir/build

src/ui/element/CMakeFiles/ui_element.dir/clean:
	cd /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element && $(CMAKE_COMMAND) -P CMakeFiles/ui_element.dir/cmake_clean.cmake
.PHONY : src/ui/element/CMakeFiles/ui_element.dir/clean

src/ui/element/CMakeFiles/ui_element.dir/depend:
	cd /home/ivo/projects/private/Engine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivo/projects/private/Engine /home/ivo/projects/private/Engine/src/ui/element /home/ivo/projects/private/Engine/cmake-build-debug /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element /home/ivo/projects/private/Engine/cmake-build-debug/src/ui/element/CMakeFiles/ui_element.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/ui/element/CMakeFiles/ui_element.dir/depend

