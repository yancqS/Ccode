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
include CMakeFiles/partV.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/partV.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/partV.dir/flags.make

CMakeFiles/partV.dir/Code/partV.c.obj: CMakeFiles/partV.dir/flags.make
CMakeFiles/partV.dir/Code/partV.c.obj: ../Code/partV.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CppCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/partV.dir/Code/partV.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\partV.dir\Code\partV.c.obj   -c D:\CppCode\Code\partV.c

CMakeFiles/partV.dir/Code/partV.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/partV.dir/Code/partV.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CppCode\Code\partV.c > CMakeFiles\partV.dir\Code\partV.c.i

CMakeFiles/partV.dir/Code/partV.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/partV.dir/Code/partV.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CppCode\Code\partV.c -o CMakeFiles\partV.dir\Code\partV.c.s

# Object files for target partV
partV_OBJECTS = \
"CMakeFiles/partV.dir/Code/partV.c.obj"

# External object files for target partV
partV_EXTERNAL_OBJECTS =

partV.exe: CMakeFiles/partV.dir/Code/partV.c.obj
partV.exe: CMakeFiles/partV.dir/build.make
partV.exe: CMakeFiles/partV.dir/linklibs.rsp
partV.exe: CMakeFiles/partV.dir/objects1.rsp
partV.exe: CMakeFiles/partV.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CppCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable partV.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\partV.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/partV.dir/build: partV.exe

.PHONY : CMakeFiles/partV.dir/build

CMakeFiles/partV.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\partV.dir\cmake_clean.cmake
.PHONY : CMakeFiles/partV.dir/clean

CMakeFiles/partV.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CppCode D:\CppCode D:\CppCode\cmake-build-debug D:\CppCode\cmake-build-debug D:\CppCode\cmake-build-debug\CMakeFiles\partV.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/partV.dir/depend

