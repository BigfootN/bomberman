# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build

# Include any dependencies generated for this target.
include 05_game/CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include 05_game/CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include 05_game/CMakeFiles/game.dir/flags.make

05_game/CMakeFiles/game.dir/gameDisplay.c.o: 05_game/CMakeFiles/game.dir/flags.make
05_game/CMakeFiles/game.dir/gameDisplay.c.o: ../05_game/gameDisplay.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 05_game/CMakeFiles/game.dir/gameDisplay.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/gameDisplay.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameDisplay.c

05_game/CMakeFiles/game.dir/gameDisplay.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/gameDisplay.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameDisplay.c > CMakeFiles/game.dir/gameDisplay.c.i

05_game/CMakeFiles/game.dir/gameDisplay.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/gameDisplay.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameDisplay.c -o CMakeFiles/game.dir/gameDisplay.c.s

05_game/CMakeFiles/game.dir/gameDisplay.c.o.requires:

.PHONY : 05_game/CMakeFiles/game.dir/gameDisplay.c.o.requires

05_game/CMakeFiles/game.dir/gameDisplay.c.o.provides: 05_game/CMakeFiles/game.dir/gameDisplay.c.o.requires
	$(MAKE) -f 05_game/CMakeFiles/game.dir/build.make 05_game/CMakeFiles/game.dir/gameDisplay.c.o.provides.build
.PHONY : 05_game/CMakeFiles/game.dir/gameDisplay.c.o.provides

05_game/CMakeFiles/game.dir/gameDisplay.c.o.provides.build: 05_game/CMakeFiles/game.dir/gameDisplay.c.o


05_game/CMakeFiles/game.dir/gameLoop.c.o: 05_game/CMakeFiles/game.dir/flags.make
05_game/CMakeFiles/game.dir/gameLoop.c.o: ../05_game/gameLoop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 05_game/CMakeFiles/game.dir/gameLoop.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/gameLoop.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameLoop.c

05_game/CMakeFiles/game.dir/gameLoop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/gameLoop.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameLoop.c > CMakeFiles/game.dir/gameLoop.c.i

05_game/CMakeFiles/game.dir/gameLoop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/gameLoop.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameLoop.c -o CMakeFiles/game.dir/gameLoop.c.s

05_game/CMakeFiles/game.dir/gameLoop.c.o.requires:

.PHONY : 05_game/CMakeFiles/game.dir/gameLoop.c.o.requires

05_game/CMakeFiles/game.dir/gameLoop.c.o.provides: 05_game/CMakeFiles/game.dir/gameLoop.c.o.requires
	$(MAKE) -f 05_game/CMakeFiles/game.dir/build.make 05_game/CMakeFiles/game.dir/gameLoop.c.o.provides.build
.PHONY : 05_game/CMakeFiles/game.dir/gameLoop.c.o.provides

05_game/CMakeFiles/game.dir/gameLoop.c.o.provides.build: 05_game/CMakeFiles/game.dir/gameLoop.c.o


05_game/CMakeFiles/game.dir/gamePanels.c.o: 05_game/CMakeFiles/game.dir/flags.make
05_game/CMakeFiles/game.dir/gamePanels.c.o: ../05_game/gamePanels.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object 05_game/CMakeFiles/game.dir/gamePanels.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/gamePanels.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gamePanels.c

05_game/CMakeFiles/game.dir/gamePanels.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/gamePanels.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gamePanels.c > CMakeFiles/game.dir/gamePanels.c.i

05_game/CMakeFiles/game.dir/gamePanels.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/gamePanels.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gamePanels.c -o CMakeFiles/game.dir/gamePanels.c.s

05_game/CMakeFiles/game.dir/gamePanels.c.o.requires:

.PHONY : 05_game/CMakeFiles/game.dir/gamePanels.c.o.requires

05_game/CMakeFiles/game.dir/gamePanels.c.o.provides: 05_game/CMakeFiles/game.dir/gamePanels.c.o.requires
	$(MAKE) -f 05_game/CMakeFiles/game.dir/build.make 05_game/CMakeFiles/game.dir/gamePanels.c.o.provides.build
.PHONY : 05_game/CMakeFiles/game.dir/gamePanels.c.o.provides

05_game/CMakeFiles/game.dir/gamePanels.c.o.provides.build: 05_game/CMakeFiles/game.dir/gamePanels.c.o


05_game/CMakeFiles/game.dir/gameTime.c.o: 05_game/CMakeFiles/game.dir/flags.make
05_game/CMakeFiles/game.dir/gameTime.c.o: ../05_game/gameTime.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object 05_game/CMakeFiles/game.dir/gameTime.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/gameTime.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameTime.c

05_game/CMakeFiles/game.dir/gameTime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/gameTime.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameTime.c > CMakeFiles/game.dir/gameTime.c.i

05_game/CMakeFiles/game.dir/gameTime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/gameTime.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameTime.c -o CMakeFiles/game.dir/gameTime.c.s

05_game/CMakeFiles/game.dir/gameTime.c.o.requires:

.PHONY : 05_game/CMakeFiles/game.dir/gameTime.c.o.requires

05_game/CMakeFiles/game.dir/gameTime.c.o.provides: 05_game/CMakeFiles/game.dir/gameTime.c.o.requires
	$(MAKE) -f 05_game/CMakeFiles/game.dir/build.make 05_game/CMakeFiles/game.dir/gameTime.c.o.provides.build
.PHONY : 05_game/CMakeFiles/game.dir/gameTime.c.o.provides

05_game/CMakeFiles/game.dir/gameTime.c.o.provides.build: 05_game/CMakeFiles/game.dir/gameTime.c.o


05_game/CMakeFiles/game.dir/gameviews.c.o: 05_game/CMakeFiles/game.dir/flags.make
05_game/CMakeFiles/game.dir/gameviews.c.o: ../05_game/gameviews.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object 05_game/CMakeFiles/game.dir/gameviews.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/game.dir/gameviews.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameviews.c

05_game/CMakeFiles/game.dir/gameviews.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/game.dir/gameviews.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameviews.c > CMakeFiles/game.dir/gameviews.c.i

05_game/CMakeFiles/game.dir/gameviews.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/game.dir/gameviews.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game/gameviews.c -o CMakeFiles/game.dir/gameviews.c.s

05_game/CMakeFiles/game.dir/gameviews.c.o.requires:

.PHONY : 05_game/CMakeFiles/game.dir/gameviews.c.o.requires

05_game/CMakeFiles/game.dir/gameviews.c.o.provides: 05_game/CMakeFiles/game.dir/gameviews.c.o.requires
	$(MAKE) -f 05_game/CMakeFiles/game.dir/build.make 05_game/CMakeFiles/game.dir/gameviews.c.o.provides.build
.PHONY : 05_game/CMakeFiles/game.dir/gameviews.c.o.provides

05_game/CMakeFiles/game.dir/gameviews.c.o.provides.build: 05_game/CMakeFiles/game.dir/gameviews.c.o


# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/gameDisplay.c.o" \
"CMakeFiles/game.dir/gameLoop.c.o" \
"CMakeFiles/game.dir/gamePanels.c.o" \
"CMakeFiles/game.dir/gameTime.c.o" \
"CMakeFiles/game.dir/gameviews.c.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

05_game/libgame.so: 05_game/CMakeFiles/game.dir/gameDisplay.c.o
05_game/libgame.so: 05_game/CMakeFiles/game.dir/gameLoop.c.o
05_game/libgame.so: 05_game/CMakeFiles/game.dir/gamePanels.c.o
05_game/libgame.so: 05_game/CMakeFiles/game.dir/gameTime.c.o
05_game/libgame.so: 05_game/CMakeFiles/game.dir/gameviews.c.o
05_game/libgame.so: 05_game/CMakeFiles/game.dir/build.make
05_game/libgame.so: 05_game/CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C shared library libgame.so"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
05_game/CMakeFiles/game.dir/build: 05_game/libgame.so

.PHONY : 05_game/CMakeFiles/game.dir/build

05_game/CMakeFiles/game.dir/requires: 05_game/CMakeFiles/game.dir/gameDisplay.c.o.requires
05_game/CMakeFiles/game.dir/requires: 05_game/CMakeFiles/game.dir/gameLoop.c.o.requires
05_game/CMakeFiles/game.dir/requires: 05_game/CMakeFiles/game.dir/gamePanels.c.o.requires
05_game/CMakeFiles/game.dir/requires: 05_game/CMakeFiles/game.dir/gameTime.c.o.requires
05_game/CMakeFiles/game.dir/requires: 05_game/CMakeFiles/game.dir/gameviews.c.o.requires

.PHONY : 05_game/CMakeFiles/game.dir/requires

05_game/CMakeFiles/game.dir/clean:
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game && $(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : 05_game/CMakeFiles/game.dir/clean

05_game/CMakeFiles/game.dir/depend:
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/05_game /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/05_game/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 05_game/CMakeFiles/game.dir/depend

