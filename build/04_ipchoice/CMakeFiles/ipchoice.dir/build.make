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
include 04_ipchoice/CMakeFiles/ipchoice.dir/depend.make

# Include the progress variables for this target.
include 04_ipchoice/CMakeFiles/ipchoice.dir/progress.make

# Include the compile flags for this target's objects.
include 04_ipchoice/CMakeFiles/ipchoice.dir/flags.make

04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o: 04_ipchoice/CMakeFiles/ipchoice.dir/flags.make
04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o: ../04_ipchoice/choiceiploop.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ipchoice.dir/choiceiploop.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choiceiploop.c

04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ipchoice.dir/choiceiploop.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choiceiploop.c > CMakeFiles/ipchoice.dir/choiceiploop.c.i

04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ipchoice.dir/choiceiploop.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choiceiploop.c -o CMakeFiles/ipchoice.dir/choiceiploop.c.s

04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.requires:

.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.requires

04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.provides: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.requires
	$(MAKE) -f 04_ipchoice/CMakeFiles/ipchoice.dir/build.make 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.provides.build
.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.provides

04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.provides.build: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o


04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o: 04_ipchoice/CMakeFiles/ipchoice.dir/flags.make
04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o: ../04_ipchoice/choiceipwindow.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ipchoice.dir/choiceipwindow.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choiceipwindow.c

04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ipchoice.dir/choiceipwindow.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choiceipwindow.c > CMakeFiles/ipchoice.dir/choiceipwindow.c.i

04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ipchoice.dir/choiceipwindow.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choiceipwindow.c -o CMakeFiles/ipchoice.dir/choiceipwindow.c.s

04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.requires:

.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.requires

04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.provides: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.requires
	$(MAKE) -f 04_ipchoice/CMakeFiles/ipchoice.dir/build.make 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.provides.build
.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.provides

04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.provides.build: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o


04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o: 04_ipchoice/CMakeFiles/ipchoice.dir/flags.make
04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o: ../04_ipchoice/choicepviews.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ipchoice.dir/choicepviews.c.o   -c /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choicepviews.c

04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ipchoice.dir/choicepviews.c.i"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choicepviews.c > CMakeFiles/ipchoice.dir/choicepviews.c.i

04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ipchoice.dir/choicepviews.c.s"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice/choicepviews.c -o CMakeFiles/ipchoice.dir/choicepviews.c.s

04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.requires:

.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.requires

04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.provides: 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.requires
	$(MAKE) -f 04_ipchoice/CMakeFiles/ipchoice.dir/build.make 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.provides.build
.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.provides

04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.provides.build: 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o


# Object files for target ipchoice
ipchoice_OBJECTS = \
"CMakeFiles/ipchoice.dir/choiceiploop.c.o" \
"CMakeFiles/ipchoice.dir/choiceipwindow.c.o" \
"CMakeFiles/ipchoice.dir/choicepviews.c.o"

# External object files for target ipchoice
ipchoice_EXTERNAL_OBJECTS =

04_ipchoice/libipchoice.so: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o
04_ipchoice/libipchoice.so: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o
04_ipchoice/libipchoice.so: 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o
04_ipchoice/libipchoice.so: 04_ipchoice/CMakeFiles/ipchoice.dir/build.make
04_ipchoice/libipchoice.so: 04_ipchoice/CMakeFiles/ipchoice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C shared library libipchoice.so"
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipchoice.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
04_ipchoice/CMakeFiles/ipchoice.dir/build: 04_ipchoice/libipchoice.so

.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/build

04_ipchoice/CMakeFiles/ipchoice.dir/requires: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceiploop.c.o.requires
04_ipchoice/CMakeFiles/ipchoice.dir/requires: 04_ipchoice/CMakeFiles/ipchoice.dir/choiceipwindow.c.o.requires
04_ipchoice/CMakeFiles/ipchoice.dir/requires: 04_ipchoice/CMakeFiles/ipchoice.dir/choicepviews.c.o.requires

.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/requires

04_ipchoice/CMakeFiles/ipchoice.dir/clean:
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice && $(CMAKE_COMMAND) -P CMakeFiles/ipchoice.dir/cmake_clean.cmake
.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/clean

04_ipchoice/CMakeFiles/ipchoice.dir/depend:
	cd /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/04_ipchoice /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice /home/bigfoot/Documents/ETNA/BOMB_QUAL/bomb_ext_git/build/04_ipchoice/CMakeFiles/ipchoice.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 04_ipchoice/CMakeFiles/ipchoice.dir/depend

