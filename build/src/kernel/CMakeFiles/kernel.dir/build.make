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
CMAKE_SOURCE_DIR = /home/bigfoot/Documents/ETNA/bomberman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigfoot/Documents/ETNA/bomberman/build

# Include any dependencies generated for this target.
include src/kernel/CMakeFiles/kernel.dir/depend.make

# Include the progress variables for this target.
include src/kernel/CMakeFiles/kernel.dir/progress.make

# Include the compile flags for this target's objects.
include src/kernel/CMakeFiles/kernel.dir/flags.make

src/kernel/CMakeFiles/kernel.dir/cleaner.c.o: src/kernel/CMakeFiles/kernel.dir/flags.make
src/kernel/CMakeFiles/kernel.dir/cleaner.c.o: ../src/kernel/cleaner.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/kernel/CMakeFiles/kernel.dir/cleaner.c.o"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/cleaner.c.o   -c /home/bigfoot/Documents/ETNA/bomberman/src/kernel/cleaner.c

src/kernel/CMakeFiles/kernel.dir/cleaner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cleaner.c.i"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/bomberman/src/kernel/cleaner.c > CMakeFiles/kernel.dir/cleaner.c.i

src/kernel/CMakeFiles/kernel.dir/cleaner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cleaner.c.s"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/bomberman/src/kernel/cleaner.c -o CMakeFiles/kernel.dir/cleaner.c.s

src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.requires:

.PHONY : src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.requires

src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.provides: src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.requires
	$(MAKE) -f src/kernel/CMakeFiles/kernel.dir/build.make src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.provides.build
.PHONY : src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.provides

src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.provides.build: src/kernel/CMakeFiles/kernel.dir/cleaner.c.o


src/kernel/CMakeFiles/kernel.dir/inits.c.o: src/kernel/CMakeFiles/kernel.dir/flags.make
src/kernel/CMakeFiles/kernel.dir/inits.c.o: ../src/kernel/inits.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/kernel/CMakeFiles/kernel.dir/inits.c.o"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/inits.c.o   -c /home/bigfoot/Documents/ETNA/bomberman/src/kernel/inits.c

src/kernel/CMakeFiles/kernel.dir/inits.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/inits.c.i"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/bomberman/src/kernel/inits.c > CMakeFiles/kernel.dir/inits.c.i

src/kernel/CMakeFiles/kernel.dir/inits.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/inits.c.s"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/bomberman/src/kernel/inits.c -o CMakeFiles/kernel.dir/inits.c.s

src/kernel/CMakeFiles/kernel.dir/inits.c.o.requires:

.PHONY : src/kernel/CMakeFiles/kernel.dir/inits.c.o.requires

src/kernel/CMakeFiles/kernel.dir/inits.c.o.provides: src/kernel/CMakeFiles/kernel.dir/inits.c.o.requires
	$(MAKE) -f src/kernel/CMakeFiles/kernel.dir/build.make src/kernel/CMakeFiles/kernel.dir/inits.c.o.provides.build
.PHONY : src/kernel/CMakeFiles/kernel.dir/inits.c.o.provides

src/kernel/CMakeFiles/kernel.dir/inits.c.o.provides.build: src/kernel/CMakeFiles/kernel.dir/inits.c.o


src/kernel/CMakeFiles/kernel.dir/linked_list.c.o: src/kernel/CMakeFiles/kernel.dir/flags.make
src/kernel/CMakeFiles/kernel.dir/linked_list.c.o: ../src/kernel/linked_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/kernel/CMakeFiles/kernel.dir/linked_list.c.o"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/linked_list.c.o   -c /home/bigfoot/Documents/ETNA/bomberman/src/kernel/linked_list.c

src/kernel/CMakeFiles/kernel.dir/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/linked_list.c.i"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/bomberman/src/kernel/linked_list.c > CMakeFiles/kernel.dir/linked_list.c.i

src/kernel/CMakeFiles/kernel.dir/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/linked_list.c.s"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/bomberman/src/kernel/linked_list.c -o CMakeFiles/kernel.dir/linked_list.c.s

src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.requires:

.PHONY : src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.requires

src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.provides: src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.requires
	$(MAKE) -f src/kernel/CMakeFiles/kernel.dir/build.make src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.provides.build
.PHONY : src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.provides

src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.provides.build: src/kernel/CMakeFiles/kernel.dir/linked_list.c.o


src/kernel/CMakeFiles/kernel.dir/kernel.c.o: src/kernel/CMakeFiles/kernel.dir/flags.make
src/kernel/CMakeFiles/kernel.dir/kernel.c.o: ../src/kernel/kernel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/Documents/ETNA/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/kernel/CMakeFiles/kernel.dir/kernel.c.o"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/kernel.c.o   -c /home/bigfoot/Documents/ETNA/bomberman/src/kernel/kernel.c

src/kernel/CMakeFiles/kernel.dir/kernel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/kernel.c.i"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/Documents/ETNA/bomberman/src/kernel/kernel.c > CMakeFiles/kernel.dir/kernel.c.i

src/kernel/CMakeFiles/kernel.dir/kernel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/kernel.c.s"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/Documents/ETNA/bomberman/src/kernel/kernel.c -o CMakeFiles/kernel.dir/kernel.c.s

src/kernel/CMakeFiles/kernel.dir/kernel.c.o.requires:

.PHONY : src/kernel/CMakeFiles/kernel.dir/kernel.c.o.requires

src/kernel/CMakeFiles/kernel.dir/kernel.c.o.provides: src/kernel/CMakeFiles/kernel.dir/kernel.c.o.requires
	$(MAKE) -f src/kernel/CMakeFiles/kernel.dir/build.make src/kernel/CMakeFiles/kernel.dir/kernel.c.o.provides.build
.PHONY : src/kernel/CMakeFiles/kernel.dir/kernel.c.o.provides

src/kernel/CMakeFiles/kernel.dir/kernel.c.o.provides.build: src/kernel/CMakeFiles/kernel.dir/kernel.c.o


# Object files for target kernel
kernel_OBJECTS = \
"CMakeFiles/kernel.dir/cleaner.c.o" \
"CMakeFiles/kernel.dir/inits.c.o" \
"CMakeFiles/kernel.dir/linked_list.c.o" \
"CMakeFiles/kernel.dir/kernel.c.o"

# External object files for target kernel
kernel_EXTERNAL_OBJECTS =

src/kernel/libkernel.so: src/kernel/CMakeFiles/kernel.dir/cleaner.c.o
src/kernel/libkernel.so: src/kernel/CMakeFiles/kernel.dir/inits.c.o
src/kernel/libkernel.so: src/kernel/CMakeFiles/kernel.dir/linked_list.c.o
src/kernel/libkernel.so: src/kernel/CMakeFiles/kernel.dir/kernel.c.o
src/kernel/libkernel.so: src/kernel/CMakeFiles/kernel.dir/build.make
src/kernel/libkernel.so: src/kernel/CMakeFiles/kernel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigfoot/Documents/ETNA/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C shared library libkernel.so"
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kernel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/kernel/CMakeFiles/kernel.dir/build: src/kernel/libkernel.so

.PHONY : src/kernel/CMakeFiles/kernel.dir/build

src/kernel/CMakeFiles/kernel.dir/requires: src/kernel/CMakeFiles/kernel.dir/cleaner.c.o.requires
src/kernel/CMakeFiles/kernel.dir/requires: src/kernel/CMakeFiles/kernel.dir/inits.c.o.requires
src/kernel/CMakeFiles/kernel.dir/requires: src/kernel/CMakeFiles/kernel.dir/linked_list.c.o.requires
src/kernel/CMakeFiles/kernel.dir/requires: src/kernel/CMakeFiles/kernel.dir/kernel.c.o.requires

.PHONY : src/kernel/CMakeFiles/kernel.dir/requires

src/kernel/CMakeFiles/kernel.dir/clean:
	cd /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel && $(CMAKE_COMMAND) -P CMakeFiles/kernel.dir/cmake_clean.cmake
.PHONY : src/kernel/CMakeFiles/kernel.dir/clean

src/kernel/CMakeFiles/kernel.dir/depend:
	cd /home/bigfoot/Documents/ETNA/bomberman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigfoot/Documents/ETNA/bomberman /home/bigfoot/Documents/ETNA/bomberman/src/kernel /home/bigfoot/Documents/ETNA/bomberman/build /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel /home/bigfoot/Documents/ETNA/bomberman/build/src/kernel/CMakeFiles/kernel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/kernel/CMakeFiles/kernel.dir/depend

