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
include CMakeFiles/partII.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/partII.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/partII.dir/flags.make

CMakeFiles/partII.dir/Code/partII.c.obj: CMakeFiles/partII.dir/flags.make
CMakeFiles/partII.dir/Code/partII.c.obj: ../Code/partII.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CppCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/partII.dir/Code/partII.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\partII.dir\Code\partII.c.obj   -c D:\CppCode\Code\partII.c

CMakeFiles/partII.dir/Code/partII.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/partII.dir/Code/partII.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CppCode\Code\partII.c > CMakeFiles\partII.dir\Code\partII.c.i

CMakeFiles/partII.dir/Code/partII.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/partII.dir/Code/partII.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CppCode\Code\partII.c -o CMakeFiles\partII.dir\Code\partII.c.s

# Object files for target partII
partII_OBJECTS = \
"CMakeFiles/partII.dir/Code/partII.c.obj"

# External object files for target partII
partII_EXTERNAL_OBJECTS =

partII.exe: CMakeFiles/partII.dir/Code/partII.c.obj
partII.exe: CMakeFiles/partII.dir/build.make
partII.exe: CMakeFiles/partII.dir/linklibs.rsp
partII.exe: CMakeFiles/partII.dir/objects1.rsp
partII.exe: CMakeFiles/partII.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CppCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable partII.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\partII.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/partII.dir/build: partII.exe

.PHONY : CMakeFiles/partII.dir/build

CMakeFiles/partII.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\partII.dir\cmake_clean.cmake
.PHONY : CMakeFiles/partII.dir/clean

CMakeFiles/partII.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CppCode D:\CppCode D:\CppCode\cmake-build-debug D:\CppCode\cmake-build-debug D:\CppCode\cmake-build-debug\CMakeFiles\partII.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/partII.dir/depend

