# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/joe/dev/cmake-3.24.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/joe/dev/cmake-3.24.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joe/dev/myBigInt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joe/dev/myBigInt

# Include any dependencies generated for this target.
include CMakeFiles/myBigIntUnitTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myBigIntUnitTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myBigIntUnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myBigIntUnitTests.dir/flags.make

CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o: CMakeFiles/myBigIntUnitTests.dir/flags.make
CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o: myBigIntTests.cpp
CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o: CMakeFiles/myBigIntUnitTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joe/dev/myBigInt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o -MF CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o.d -o CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o -c /home/joe/dev/myBigInt/myBigIntTests.cpp

CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joe/dev/myBigInt/myBigIntTests.cpp > CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.i

CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joe/dev/myBigInt/myBigIntTests.cpp -o CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.s

# Object files for target myBigIntUnitTests
myBigIntUnitTests_OBJECTS = \
"CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o"

# External object files for target myBigIntUnitTests
myBigIntUnitTests_EXTERNAL_OBJECTS =

myBigIntUnitTests: CMakeFiles/myBigIntUnitTests.dir/myBigIntTests.cpp.o
myBigIntUnitTests: CMakeFiles/myBigIntUnitTests.dir/build.make
myBigIntUnitTests: myBigInt/libmybigint.a
myBigIntUnitTests: lib/libgtest_main.a
myBigIntUnitTests: lib/libgtest.a
myBigIntUnitTests: CMakeFiles/myBigIntUnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joe/dev/myBigInt/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myBigIntUnitTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myBigIntUnitTests.dir/link.txt --verbose=$(VERBOSE)
	/home/joe/dev/cmake-3.24.1-linux-x86_64/bin/cmake -D TEST_TARGET=myBigIntUnitTests -D TEST_EXECUTABLE=/home/joe/dev/myBigInt/myBigIntUnitTests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/joe/dev/myBigInt -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=myBigIntUnitTests_TESTS -D CTEST_FILE=/home/joe/dev/myBigInt/myBigIntUnitTests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /home/joe/dev/cmake-3.24.1-linux-x86_64/share/cmake-3.24/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/myBigIntUnitTests.dir/build: myBigIntUnitTests
.PHONY : CMakeFiles/myBigIntUnitTests.dir/build

CMakeFiles/myBigIntUnitTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myBigIntUnitTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myBigIntUnitTests.dir/clean

CMakeFiles/myBigIntUnitTests.dir/depend:
	cd /home/joe/dev/myBigInt && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joe/dev/myBigInt /home/joe/dev/myBigInt /home/joe/dev/myBigInt /home/joe/dev/myBigInt /home/joe/dev/myBigInt/CMakeFiles/myBigIntUnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myBigIntUnitTests.dir/depend

