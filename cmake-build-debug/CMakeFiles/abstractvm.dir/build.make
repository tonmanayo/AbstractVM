# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/tony/Downloads/clion-2017.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/tony/Downloads/clion-2017.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tony/Projects/AbstractVM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tony/Projects/AbstractVM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/abstractvm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/abstractvm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abstractvm.dir/flags.make

CMakeFiles/abstractvm.dir/main.cpp.o: CMakeFiles/abstractvm.dir/flags.make
CMakeFiles/abstractvm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/Projects/AbstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/abstractvm.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractvm.dir/main.cpp.o -c /home/tony/Projects/AbstractVM/main.cpp

CMakeFiles/abstractvm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractvm.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/Projects/AbstractVM/main.cpp > CMakeFiles/abstractvm.dir/main.cpp.i

CMakeFiles/abstractvm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractvm.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/Projects/AbstractVM/main.cpp -o CMakeFiles/abstractvm.dir/main.cpp.s

CMakeFiles/abstractvm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/abstractvm.dir/main.cpp.o.requires

CMakeFiles/abstractvm.dir/main.cpp.o.provides: CMakeFiles/abstractvm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/abstractvm.dir/build.make CMakeFiles/abstractvm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/abstractvm.dir/main.cpp.o.provides

CMakeFiles/abstractvm.dir/main.cpp.o.provides.build: CMakeFiles/abstractvm.dir/main.cpp.o


CMakeFiles/abstractvm.dir/VMFactory.cpp.o: CMakeFiles/abstractvm.dir/flags.make
CMakeFiles/abstractvm.dir/VMFactory.cpp.o: ../VMFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tony/Projects/AbstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/abstractvm.dir/VMFactory.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractvm.dir/VMFactory.cpp.o -c /home/tony/Projects/AbstractVM/VMFactory.cpp

CMakeFiles/abstractvm.dir/VMFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractvm.dir/VMFactory.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tony/Projects/AbstractVM/VMFactory.cpp > CMakeFiles/abstractvm.dir/VMFactory.cpp.i

CMakeFiles/abstractvm.dir/VMFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractvm.dir/VMFactory.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tony/Projects/AbstractVM/VMFactory.cpp -o CMakeFiles/abstractvm.dir/VMFactory.cpp.s

CMakeFiles/abstractvm.dir/VMFactory.cpp.o.requires:

.PHONY : CMakeFiles/abstractvm.dir/VMFactory.cpp.o.requires

CMakeFiles/abstractvm.dir/VMFactory.cpp.o.provides: CMakeFiles/abstractvm.dir/VMFactory.cpp.o.requires
	$(MAKE) -f CMakeFiles/abstractvm.dir/build.make CMakeFiles/abstractvm.dir/VMFactory.cpp.o.provides.build
.PHONY : CMakeFiles/abstractvm.dir/VMFactory.cpp.o.provides

CMakeFiles/abstractvm.dir/VMFactory.cpp.o.provides.build: CMakeFiles/abstractvm.dir/VMFactory.cpp.o


# Object files for target abstractvm
abstractvm_OBJECTS = \
"CMakeFiles/abstractvm.dir/main.cpp.o" \
"CMakeFiles/abstractvm.dir/VMFactory.cpp.o"

# External object files for target abstractvm
abstractvm_EXTERNAL_OBJECTS =

abstractvm: CMakeFiles/abstractvm.dir/main.cpp.o
abstractvm: CMakeFiles/abstractvm.dir/VMFactory.cpp.o
abstractvm: CMakeFiles/abstractvm.dir/build.make
abstractvm: CMakeFiles/abstractvm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tony/Projects/AbstractVM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable abstractvm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abstractvm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abstractvm.dir/build: abstractvm

.PHONY : CMakeFiles/abstractvm.dir/build

CMakeFiles/abstractvm.dir/requires: CMakeFiles/abstractvm.dir/main.cpp.o.requires
CMakeFiles/abstractvm.dir/requires: CMakeFiles/abstractvm.dir/VMFactory.cpp.o.requires

.PHONY : CMakeFiles/abstractvm.dir/requires

CMakeFiles/abstractvm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/abstractvm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/abstractvm.dir/clean

CMakeFiles/abstractvm.dir/depend:
	cd /home/tony/Projects/AbstractVM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tony/Projects/AbstractVM /home/tony/Projects/AbstractVM /home/tony/Projects/AbstractVM/cmake-build-debug /home/tony/Projects/AbstractVM/cmake-build-debug /home/tony/Projects/AbstractVM/cmake-build-debug/CMakeFiles/abstractvm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/abstractvm.dir/depend

