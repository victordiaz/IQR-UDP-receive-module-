# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/biquillo/iqr/UDPreceive

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/biquillo/iqr/UDPreceive

# Include any dependencies generated for this target.
include CMakeFiles/UDPreceive.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UDPreceive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UDPreceive.dir/flags.make

CMakeFiles/UDPreceive.dir/UDPreceive.o: CMakeFiles/UDPreceive.dir/flags.make
CMakeFiles/UDPreceive.dir/UDPreceive.o: UDPreceive.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/biquillo/iqr/UDPreceive/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/UDPreceive.dir/UDPreceive.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/UDPreceive.dir/UDPreceive.o -c /home/biquillo/iqr/UDPreceive/UDPreceive.cpp

CMakeFiles/UDPreceive.dir/UDPreceive.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDPreceive.dir/UDPreceive.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/biquillo/iqr/UDPreceive/UDPreceive.cpp > CMakeFiles/UDPreceive.dir/UDPreceive.i

CMakeFiles/UDPreceive.dir/UDPreceive.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDPreceive.dir/UDPreceive.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/biquillo/iqr/UDPreceive/UDPreceive.cpp -o CMakeFiles/UDPreceive.dir/UDPreceive.s

CMakeFiles/UDPreceive.dir/UDPreceive.o.requires:
.PHONY : CMakeFiles/UDPreceive.dir/UDPreceive.o.requires

CMakeFiles/UDPreceive.dir/UDPreceive.o.provides: CMakeFiles/UDPreceive.dir/UDPreceive.o.requires
	$(MAKE) -f CMakeFiles/UDPreceive.dir/build.make CMakeFiles/UDPreceive.dir/UDPreceive.o.provides.build
.PHONY : CMakeFiles/UDPreceive.dir/UDPreceive.o.provides

CMakeFiles/UDPreceive.dir/UDPreceive.o.provides.build: CMakeFiles/UDPreceive.dir/UDPreceive.o
.PHONY : CMakeFiles/UDPreceive.dir/UDPreceive.o.provides.build

# Object files for target UDPreceive
UDPreceive_OBJECTS = \
"CMakeFiles/UDPreceive.dir/UDPreceive.o"

# External object files for target UDPreceive
UDPreceive_EXTERNAL_OBJECTS =

UDPreceive.so: CMakeFiles/UDPreceive.dir/UDPreceive.o
UDPreceive.so: CMakeFiles/UDPreceive.dir/build.make
UDPreceive.so: CMakeFiles/UDPreceive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library UDPreceive.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UDPreceive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UDPreceive.dir/build: UDPreceive.so
.PHONY : CMakeFiles/UDPreceive.dir/build

CMakeFiles/UDPreceive.dir/requires: CMakeFiles/UDPreceive.dir/UDPreceive.o.requires
.PHONY : CMakeFiles/UDPreceive.dir/requires

CMakeFiles/UDPreceive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UDPreceive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UDPreceive.dir/clean

CMakeFiles/UDPreceive.dir/depend:
	cd /home/biquillo/iqr/UDPreceive && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/biquillo/iqr/UDPreceive /home/biquillo/iqr/UDPreceive /home/biquillo/iqr/UDPreceive /home/biquillo/iqr/UDPreceive /home/biquillo/iqr/UDPreceive/CMakeFiles/UDPreceive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UDPreceive.dir/depend

