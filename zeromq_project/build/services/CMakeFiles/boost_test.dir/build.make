# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/hjiang/cpp_workout/zeromq_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hjiang/cpp_workout/zeromq_project/build

# Include any dependencies generated for this target.
include services/CMakeFiles/boost_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include services/CMakeFiles/boost_test.dir/compiler_depend.make

# Include the progress variables for this target.
include services/CMakeFiles/boost_test.dir/progress.make

# Include the compile flags for this target's objects.
include services/CMakeFiles/boost_test.dir/flags.make

services/CMakeFiles/boost_test.dir/boost_test.cc.o: services/CMakeFiles/boost_test.dir/flags.make
services/CMakeFiles/boost_test.dir/boost_test.cc.o: ../services/boost_test.cc
services/CMakeFiles/boost_test.dir/boost_test.cc.o: services/CMakeFiles/boost_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hjiang/cpp_workout/zeromq_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object services/CMakeFiles/boost_test.dir/boost_test.cc.o"
	cd /home/hjiang/cpp_workout/zeromq_project/build/services && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT services/CMakeFiles/boost_test.dir/boost_test.cc.o -MF CMakeFiles/boost_test.dir/boost_test.cc.o.d -o CMakeFiles/boost_test.dir/boost_test.cc.o -c /home/hjiang/cpp_workout/zeromq_project/services/boost_test.cc

services/CMakeFiles/boost_test.dir/boost_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_test.dir/boost_test.cc.i"
	cd /home/hjiang/cpp_workout/zeromq_project/build/services && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hjiang/cpp_workout/zeromq_project/services/boost_test.cc > CMakeFiles/boost_test.dir/boost_test.cc.i

services/CMakeFiles/boost_test.dir/boost_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_test.dir/boost_test.cc.s"
	cd /home/hjiang/cpp_workout/zeromq_project/build/services && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hjiang/cpp_workout/zeromq_project/services/boost_test.cc -o CMakeFiles/boost_test.dir/boost_test.cc.s

# Object files for target boost_test
boost_test_OBJECTS = \
"CMakeFiles/boost_test.dir/boost_test.cc.o"

# External object files for target boost_test
boost_test_EXTERNAL_OBJECTS =

services/boost_test: services/CMakeFiles/boost_test.dir/boost_test.cc.o
services/boost_test: services/CMakeFiles/boost_test.dir/build.make
services/boost_test: services/CMakeFiles/boost_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hjiang/cpp_workout/zeromq_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boost_test"
	cd /home/hjiang/cpp_workout/zeromq_project/build/services && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
services/CMakeFiles/boost_test.dir/build: services/boost_test
.PHONY : services/CMakeFiles/boost_test.dir/build

services/CMakeFiles/boost_test.dir/clean:
	cd /home/hjiang/cpp_workout/zeromq_project/build/services && $(CMAKE_COMMAND) -P CMakeFiles/boost_test.dir/cmake_clean.cmake
.PHONY : services/CMakeFiles/boost_test.dir/clean

services/CMakeFiles/boost_test.dir/depend:
	cd /home/hjiang/cpp_workout/zeromq_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hjiang/cpp_workout/zeromq_project /home/hjiang/cpp_workout/zeromq_project/services /home/hjiang/cpp_workout/zeromq_project/build /home/hjiang/cpp_workout/zeromq_project/build/services /home/hjiang/cpp_workout/zeromq_project/build/services/CMakeFiles/boost_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : services/CMakeFiles/boost_test.dir/depend
