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
CMAKE_COMMAND = D:/ProgramFiles/cmake-3.24.2-windows-x86_64/bin/cmake.exe

# The command to remove a file.
RM = D:/ProgramFiles/cmake-3.24.2-windows-x86_64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/workspace/c_code/reservation2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/workspace/c_code/reservation2/build

# Include any dependencies generated for this target.
include CMakeFiles/reservation2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reservation2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reservation2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reservation2.dir/flags.make

CMakeFiles/reservation2.dir/src/global_file.cpp.obj: CMakeFiles/reservation2.dir/flags.make
CMakeFiles/reservation2.dir/src/global_file.cpp.obj: CMakeFiles/reservation2.dir/includes_CXX.rsp
CMakeFiles/reservation2.dir/src/global_file.cpp.obj: D:/workspace/c_code/reservation2/src/global_file.cpp
CMakeFiles/reservation2.dir/src/global_file.cpp.obj: CMakeFiles/reservation2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/workspace/c_code/reservation2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reservation2.dir/src/global_file.cpp.obj"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reservation2.dir/src/global_file.cpp.obj -MF CMakeFiles/reservation2.dir/src/global_file.cpp.obj.d -o CMakeFiles/reservation2.dir/src/global_file.cpp.obj -c D:/workspace/c_code/reservation2/src/global_file.cpp

CMakeFiles/reservation2.dir/src/global_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reservation2.dir/src/global_file.cpp.i"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/workspace/c_code/reservation2/src/global_file.cpp > CMakeFiles/reservation2.dir/src/global_file.cpp.i

CMakeFiles/reservation2.dir/src/global_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reservation2.dir/src/global_file.cpp.s"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/workspace/c_code/reservation2/src/global_file.cpp -o CMakeFiles/reservation2.dir/src/global_file.cpp.s

CMakeFiles/reservation2.dir/src/main.cpp.obj: CMakeFiles/reservation2.dir/flags.make
CMakeFiles/reservation2.dir/src/main.cpp.obj: CMakeFiles/reservation2.dir/includes_CXX.rsp
CMakeFiles/reservation2.dir/src/main.cpp.obj: D:/workspace/c_code/reservation2/src/main.cpp
CMakeFiles/reservation2.dir/src/main.cpp.obj: CMakeFiles/reservation2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/workspace/c_code/reservation2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reservation2.dir/src/main.cpp.obj"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reservation2.dir/src/main.cpp.obj -MF CMakeFiles/reservation2.dir/src/main.cpp.obj.d -o CMakeFiles/reservation2.dir/src/main.cpp.obj -c D:/workspace/c_code/reservation2/src/main.cpp

CMakeFiles/reservation2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reservation2.dir/src/main.cpp.i"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/workspace/c_code/reservation2/src/main.cpp > CMakeFiles/reservation2.dir/src/main.cpp.i

CMakeFiles/reservation2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reservation2.dir/src/main.cpp.s"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/workspace/c_code/reservation2/src/main.cpp -o CMakeFiles/reservation2.dir/src/main.cpp.s

CMakeFiles/reservation2.dir/src/order_file.cpp.obj: CMakeFiles/reservation2.dir/flags.make
CMakeFiles/reservation2.dir/src/order_file.cpp.obj: CMakeFiles/reservation2.dir/includes_CXX.rsp
CMakeFiles/reservation2.dir/src/order_file.cpp.obj: D:/workspace/c_code/reservation2/src/order_file.cpp
CMakeFiles/reservation2.dir/src/order_file.cpp.obj: CMakeFiles/reservation2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/workspace/c_code/reservation2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/reservation2.dir/src/order_file.cpp.obj"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reservation2.dir/src/order_file.cpp.obj -MF CMakeFiles/reservation2.dir/src/order_file.cpp.obj.d -o CMakeFiles/reservation2.dir/src/order_file.cpp.obj -c D:/workspace/c_code/reservation2/src/order_file.cpp

CMakeFiles/reservation2.dir/src/order_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reservation2.dir/src/order_file.cpp.i"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/workspace/c_code/reservation2/src/order_file.cpp > CMakeFiles/reservation2.dir/src/order_file.cpp.i

CMakeFiles/reservation2.dir/src/order_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reservation2.dir/src/order_file.cpp.s"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/workspace/c_code/reservation2/src/order_file.cpp -o CMakeFiles/reservation2.dir/src/order_file.cpp.s

CMakeFiles/reservation2.dir/src/persons.cpp.obj: CMakeFiles/reservation2.dir/flags.make
CMakeFiles/reservation2.dir/src/persons.cpp.obj: CMakeFiles/reservation2.dir/includes_CXX.rsp
CMakeFiles/reservation2.dir/src/persons.cpp.obj: D:/workspace/c_code/reservation2/src/persons.cpp
CMakeFiles/reservation2.dir/src/persons.cpp.obj: CMakeFiles/reservation2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/workspace/c_code/reservation2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/reservation2.dir/src/persons.cpp.obj"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reservation2.dir/src/persons.cpp.obj -MF CMakeFiles/reservation2.dir/src/persons.cpp.obj.d -o CMakeFiles/reservation2.dir/src/persons.cpp.obj -c D:/workspace/c_code/reservation2/src/persons.cpp

CMakeFiles/reservation2.dir/src/persons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/reservation2.dir/src/persons.cpp.i"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/workspace/c_code/reservation2/src/persons.cpp > CMakeFiles/reservation2.dir/src/persons.cpp.i

CMakeFiles/reservation2.dir/src/persons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/reservation2.dir/src/persons.cpp.s"
	D:/ProgramFiles/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/workspace/c_code/reservation2/src/persons.cpp -o CMakeFiles/reservation2.dir/src/persons.cpp.s

# Object files for target reservation2
reservation2_OBJECTS = \
"CMakeFiles/reservation2.dir/src/global_file.cpp.obj" \
"CMakeFiles/reservation2.dir/src/main.cpp.obj" \
"CMakeFiles/reservation2.dir/src/order_file.cpp.obj" \
"CMakeFiles/reservation2.dir/src/persons.cpp.obj"

# External object files for target reservation2
reservation2_EXTERNAL_OBJECTS =

reservation2.exe: CMakeFiles/reservation2.dir/src/global_file.cpp.obj
reservation2.exe: CMakeFiles/reservation2.dir/src/main.cpp.obj
reservation2.exe: CMakeFiles/reservation2.dir/src/order_file.cpp.obj
reservation2.exe: CMakeFiles/reservation2.dir/src/persons.cpp.obj
reservation2.exe: CMakeFiles/reservation2.dir/build.make
reservation2.exe: CMakeFiles/reservation2.dir/linklibs.rsp
reservation2.exe: CMakeFiles/reservation2.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/workspace/c_code/reservation2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable reservation2.exe"
	D:/ProgramFiles/cmake-3.24.2-windows-x86_64/bin/cmake.exe -E rm -f CMakeFiles/reservation2.dir/objects.a
	D:/ProgramFiles/mingw64/bin/ar.exe qc CMakeFiles/reservation2.dir/objects.a @CMakeFiles/reservation2.dir/objects1.rsp
	D:/ProgramFiles/mingw64/bin/c++.exe -Wl,--whole-archive CMakeFiles/reservation2.dir/objects.a -Wl,--no-whole-archive -o reservation2.exe -Wl,--out-implib,libreservation2.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/reservation2.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/reservation2.dir/build: reservation2.exe
.PHONY : CMakeFiles/reservation2.dir/build

CMakeFiles/reservation2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reservation2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reservation2.dir/clean

CMakeFiles/reservation2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/workspace/c_code/reservation2 D:/workspace/c_code/reservation2 D:/workspace/c_code/reservation2/build D:/workspace/c_code/reservation2/build D:/workspace/c_code/reservation2/build/CMakeFiles/reservation2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/reservation2.dir/depend

