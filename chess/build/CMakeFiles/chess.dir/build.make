# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/codegen:
.PHONY : CMakeFiles/chess.dir/codegen

CMakeFiles/chess.dir/src/board_ui.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/board_ui.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/board_ui.cpp.obj: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/src/board_ui.cpp
CMakeFiles/chess.dir/src/board_ui.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/src/board_ui.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/board_ui.cpp.obj -MF CMakeFiles\chess.dir\src\board_ui.cpp.obj.d -o CMakeFiles\chess.dir\src\board_ui.cpp.obj -c C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\board_ui.cpp

CMakeFiles/chess.dir/src/board_ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/board_ui.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\board_ui.cpp > CMakeFiles\chess.dir\src\board_ui.cpp.i

CMakeFiles/chess.dir/src/board_ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/board_ui.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\board_ui.cpp -o CMakeFiles\chess.dir\src\board_ui.cpp.s

CMakeFiles/chess.dir/src/boardstates.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/boardstates.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/boardstates.cpp.obj: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/src/boardstates.cpp
CMakeFiles/chess.dir/src/boardstates.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/src/boardstates.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/boardstates.cpp.obj -MF CMakeFiles\chess.dir\src\boardstates.cpp.obj.d -o CMakeFiles\chess.dir\src\boardstates.cpp.obj -c C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\boardstates.cpp

CMakeFiles/chess.dir/src/boardstates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/boardstates.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\boardstates.cpp > CMakeFiles\chess.dir\src\boardstates.cpp.i

CMakeFiles/chess.dir/src/boardstates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/boardstates.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\boardstates.cpp -o CMakeFiles\chess.dir\src\boardstates.cpp.s

CMakeFiles/chess.dir/src/main.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/main.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/main.cpp.obj: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/src/main.cpp
CMakeFiles/chess.dir/src/main.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/main.cpp.obj -MF CMakeFiles\chess.dir\src\main.cpp.obj.d -o CMakeFiles\chess.dir\src\main.cpp.obj -c C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\main.cpp

CMakeFiles/chess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\main.cpp > CMakeFiles\chess.dir\src\main.cpp.i

CMakeFiles/chess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\main.cpp -o CMakeFiles\chess.dir\src\main.cpp.s

CMakeFiles/chess.dir/src/pieces.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/src/pieces.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/src/pieces.cpp.obj: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/src/pieces.cpp
CMakeFiles/chess.dir/src/pieces.cpp.obj: CMakeFiles/chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/src/pieces.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/chess.dir/src/pieces.cpp.obj -MF CMakeFiles\chess.dir\src\pieces.cpp.obj.d -o CMakeFiles\chess.dir\src\pieces.cpp.obj -c C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\pieces.cpp

CMakeFiles/chess.dir/src/pieces.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/chess.dir/src/pieces.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\pieces.cpp > CMakeFiles\chess.dir\src\pieces.cpp.i

CMakeFiles/chess.dir/src/pieces.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/chess.dir/src/pieces.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\src\pieces.cpp -o CMakeFiles\chess.dir\src\pieces.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/src/board_ui.cpp.obj" \
"CMakeFiles/chess.dir/src/boardstates.cpp.obj" \
"CMakeFiles/chess.dir/src/main.cpp.obj" \
"CMakeFiles/chess.dir/src/pieces.cpp.obj"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

bin/chess.exe: CMakeFiles/chess.dir/src/board_ui.cpp.obj
bin/chess.exe: CMakeFiles/chess.dir/src/boardstates.cpp.obj
bin/chess.exe: CMakeFiles/chess.dir/src/main.cpp.obj
bin/chess.exe: CMakeFiles/chess.dir/src/pieces.cpp.obj
bin/chess.exe: CMakeFiles/chess.dir/build.make
bin/chess.exe: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/lib/libsfml-graphics.a
bin/chess.exe: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/lib/libsfml-window.a
bin/chess.exe: C:/Users/rohan/OneDrive/Documents/GitHub/Chess/chess/lib/libsfml-system.a
bin/chess.exe: CMakeFiles/chess.dir/linkLibs.rsp
bin/chess.exe: CMakeFiles/chess.dir/objects1.rsp
bin/chess.exe: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin\chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: bin/chess.exe
.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build C:\Users\rohan\OneDrive\Documents\GitHub\Chess\chess\build\CMakeFiles\chess.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/chess.dir/depend

