# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ABDuran\CLionProjects\BST_FinalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ABDuran\CLionProjects\BST_FinalProject\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BST_FinalProject.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BST_FinalProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BST_FinalProject.dir/flags.make

CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.obj: CMakeFiles/BST_FinalProject.dir/flags.make
CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.obj: ../wordfreq.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ABDuran\CLionProjects\BST_FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BST_FinalProject.dir\wordfreq.cpp.obj -c C:\Users\ABDuran\CLionProjects\BST_FinalProject\wordfreq.cpp

CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ABDuran\CLionProjects\BST_FinalProject\wordfreq.cpp > CMakeFiles\BST_FinalProject.dir\wordfreq.cpp.i

CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ABDuran\CLionProjects\BST_FinalProject\wordfreq.cpp -o CMakeFiles\BST_FinalProject.dir\wordfreq.cpp.s

# Object files for target BST_FinalProject
BST_FinalProject_OBJECTS = \
"CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.obj"

# External object files for target BST_FinalProject
BST_FinalProject_EXTERNAL_OBJECTS =

BST_FinalProject.exe: CMakeFiles/BST_FinalProject.dir/wordfreq.cpp.obj
BST_FinalProject.exe: CMakeFiles/BST_FinalProject.dir/build.make
BST_FinalProject.exe: CMakeFiles/BST_FinalProject.dir/linklibs.rsp
BST_FinalProject.exe: CMakeFiles/BST_FinalProject.dir/objects1.rsp
BST_FinalProject.exe: CMakeFiles/BST_FinalProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ABDuran\CLionProjects\BST_FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BST_FinalProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BST_FinalProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BST_FinalProject.dir/build: BST_FinalProject.exe
.PHONY : CMakeFiles/BST_FinalProject.dir/build

CMakeFiles/BST_FinalProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BST_FinalProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BST_FinalProject.dir/clean

CMakeFiles/BST_FinalProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ABDuran\CLionProjects\BST_FinalProject C:\Users\ABDuran\CLionProjects\BST_FinalProject C:\Users\ABDuran\CLionProjects\BST_FinalProject\cmake-build-debug C:\Users\ABDuran\CLionProjects\BST_FinalProject\cmake-build-debug C:\Users\ABDuran\CLionProjects\BST_FinalProject\cmake-build-debug\CMakeFiles\BST_FinalProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BST_FinalProject.dir/depend

