# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build

# Include any dependencies generated for this target.
include CMakeFiles/tarea.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tarea.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tarea.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tarea.dir/flags.make

CMakeFiles/tarea.dir/tarea.cpp.o: CMakeFiles/tarea.dir/flags.make
CMakeFiles/tarea.dir/tarea.cpp.o: /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/tarea.cpp
CMakeFiles/tarea.dir/tarea.cpp.o: CMakeFiles/tarea.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tarea.dir/tarea.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tarea.dir/tarea.cpp.o -MF CMakeFiles/tarea.dir/tarea.cpp.o.d -o CMakeFiles/tarea.dir/tarea.cpp.o -c /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/tarea.cpp

CMakeFiles/tarea.dir/tarea.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tarea.dir/tarea.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/tarea.cpp > CMakeFiles/tarea.dir/tarea.cpp.i

CMakeFiles/tarea.dir/tarea.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tarea.dir/tarea.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/tarea.cpp -o CMakeFiles/tarea.dir/tarea.cpp.s

# Object files for target tarea
tarea_OBJECTS = \
"CMakeFiles/tarea.dir/tarea.cpp.o"

# External object files for target tarea
tarea_EXTERNAL_OBJECTS =

tarea: CMakeFiles/tarea.dir/tarea.cpp.o
tarea: CMakeFiles/tarea.dir/build.make
tarea: CMakeFiles/tarea.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tarea"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tarea.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tarea.dir/build: tarea
.PHONY : CMakeFiles/tarea.dir/build

CMakeFiles/tarea.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tarea.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tarea.dir/clean

CMakeFiles/tarea.dir/depend:
	cd /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build /home/lenovo/Documentos/2024-A/CC2/15_04/ejercicios/build/CMakeFiles/tarea.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tarea.dir/depend

