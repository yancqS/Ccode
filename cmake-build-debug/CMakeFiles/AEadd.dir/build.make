# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.11

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\MinGW\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\MinGW\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CppCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CppCode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AEadd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AEadd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AEadd.dir/flags.make

CMakeFiles/AEadd.dir/fileCode/AEadd.c.obj: CMakeFiles/AEadd.dir/flags.make
CMakeFiles/AEadd.dir/fileCode/AEadd.c.obj: ../fileCode/AEadd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CppCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AEadd.dir/fileCode/AEadd.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\AEadd.dir\fileCode\AEadd.c.obj   -c D:\CppCode\fileCode\AEadd.c

CMakeFiles/AEadd.dir/fileCode/AEadd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AEadd.dir/fileCode/AEadd.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CppCode\fileCode\AEadd.c > CMakeFiles\AEadd.dir\fileCode\AEadd.c.i

CMakeFiles/AEadd.dir/fileCode/AEadd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AEadd.dir/fileCode/AEadd.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CppCode\fileCode\AEadd.c -o CMakeFiles\AEadd.dir\fileCode\AEadd.c.s

# Object files for target AEadd
AEadd_OBJECTS = \
"CMakeFiles/AEadd.dir/fileCode/AEadd.c.obj"

# External object files for target AEadd
AEadd_EXTERNAL_OBJECTS =

AEadd.exe: CMakeFiles/AEadd.dir/fileCode/AEadd.c.obj
AEadd.exe: CMakeFiles/AEadd.dir/build.make
AEadd.exe: CMakeFiles/AEadd.dir/linklibs.rsp
AEadd.exe: CMakeFiles/AEadd.dir/objects1.rsp
AEadd.exe: CMakeFiles/AEadd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CppCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable AEadd.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AEadd.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AEadd.dir/build: AEadd.exe

.PHONY : CMakeFiles/AEadd.dir/build

CMakeFiles/AEadd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AEadd.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AEadd.dir/clean

CMakeFiles/AEadd.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CppCode D:\CppCode D:\CppCode\cmake-build-debug D:\CppCode\cmake-build-debug D:\CppCode\cmake-build-debug\CMakeFiles\AEadd.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AEadd.dir/depend
