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
CMAKE_SOURCE_DIR = /home/bigfoot/bomberman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigfoot/bomberman/build

# Include any dependencies generated for this target.
include src/ai/CMakeFiles/ai.dir/depend.make

# Include the progress variables for this target.
include src/ai/CMakeFiles/ai.dir/progress.make

# Include the compile flags for this target's objects.
include src/ai/CMakeFiles/ai.dir/flags.make

src/ai/CMakeFiles/ai.dir/ai.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai.c.o: ../src/ai/ai.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/ai/CMakeFiles/ai.dir/ai.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai.c.o   -c /home/bigfoot/bomberman/src/ai/ai.c

src/ai/CMakeFiles/ai.dir/ai.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai.c > CMakeFiles/ai.dir/ai.c.i

src/ai/CMakeFiles/ai.dir/ai.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai.c -o CMakeFiles/ai.dir/ai.c.s

src/ai/CMakeFiles/ai.dir/ai.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai.c.o.requires

src/ai/CMakeFiles/ai.dir/ai.c.o.provides: src/ai/CMakeFiles/ai.dir/ai.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai.c.o.provides

src/ai/CMakeFiles/ai.dir/ai.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai.c.o


src/ai/CMakeFiles/ai.dir/ai_bomb.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_bomb.c.o: ../src/ai/ai_bomb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/ai/CMakeFiles/ai.dir/ai_bomb.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_bomb.c.o   -c /home/bigfoot/bomberman/src/ai/ai_bomb.c

src/ai/CMakeFiles/ai.dir/ai_bomb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_bomb.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_bomb.c > CMakeFiles/ai.dir/ai_bomb.c.i

src/ai/CMakeFiles/ai.dir/ai_bomb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_bomb.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_bomb.c -o CMakeFiles/ai.dir/ai_bomb.c.s

src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_bomb.c.o


src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o: ../src/ai/ai_bonus_penalty.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_bonus_penalty.c.o   -c /home/bigfoot/bomberman/src/ai/ai_bonus_penalty.c

src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_bonus_penalty.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_bonus_penalty.c > CMakeFiles/ai.dir/ai_bonus_penalty.c.i

src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_bonus_penalty.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_bonus_penalty.c -o CMakeFiles/ai.dir/ai_bonus_penalty.c.s

src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o


src/ai/CMakeFiles/ai.dir/ai_counter.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_counter.c.o: ../src/ai/ai_counter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/ai/CMakeFiles/ai.dir/ai_counter.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_counter.c.o   -c /home/bigfoot/bomberman/src/ai/ai_counter.c

src/ai/CMakeFiles/ai.dir/ai_counter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_counter.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_counter.c > CMakeFiles/ai.dir/ai_counter.c.i

src/ai/CMakeFiles/ai.dir/ai_counter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_counter.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_counter.c -o CMakeFiles/ai.dir/ai_counter.c.s

src/ai/CMakeFiles/ai.dir/ai_counter.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_counter.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_counter.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_counter.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_counter.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_counter.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_counter.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_counter.c.o


src/ai/CMakeFiles/ai.dir/ai_dead.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_dead.c.o: ../src/ai/ai_dead.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/ai/CMakeFiles/ai.dir/ai_dead.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_dead.c.o   -c /home/bigfoot/bomberman/src/ai/ai_dead.c

src/ai/CMakeFiles/ai.dir/ai_dead.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_dead.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_dead.c > CMakeFiles/ai.dir/ai_dead.c.i

src/ai/CMakeFiles/ai.dir/ai_dead.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_dead.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_dead.c -o CMakeFiles/ai.dir/ai_dead.c.s

src/ai/CMakeFiles/ai.dir/ai_dead.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_dead.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_dead.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_dead.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_dead.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_dead.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_dead.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_dead.c.o


src/ai/CMakeFiles/ai.dir/ai_blast.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_blast.c.o: ../src/ai/ai_blast.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/ai/CMakeFiles/ai.dir/ai_blast.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_blast.c.o   -c /home/bigfoot/bomberman/src/ai/ai_blast.c

src/ai/CMakeFiles/ai.dir/ai_blast.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_blast.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_blast.c > CMakeFiles/ai.dir/ai_blast.c.i

src/ai/CMakeFiles/ai.dir/ai_blast.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_blast.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_blast.c -o CMakeFiles/ai.dir/ai_blast.c.s

src/ai/CMakeFiles/ai.dir/ai_blast.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_blast.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_blast.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_blast.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_blast.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_blast.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_blast.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_blast.c.o


src/ai/CMakeFiles/ai.dir/ai_map.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_map.c.o: ../src/ai/ai_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/ai/CMakeFiles/ai.dir/ai_map.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_map.c.o   -c /home/bigfoot/bomberman/src/ai/ai_map.c

src/ai/CMakeFiles/ai.dir/ai_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_map.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_map.c > CMakeFiles/ai.dir/ai_map.c.i

src/ai/CMakeFiles/ai.dir/ai_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_map.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_map.c -o CMakeFiles/ai.dir/ai_map.c.s

src/ai/CMakeFiles/ai.dir/ai_map.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_map.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_map.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_map.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_map.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_map.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_map.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_map.c.o


src/ai/CMakeFiles/ai.dir/ai_monster.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_monster.c.o: ../src/ai/ai_monster.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/ai/CMakeFiles/ai.dir/ai_monster.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_monster.c.o   -c /home/bigfoot/bomberman/src/ai/ai_monster.c

src/ai/CMakeFiles/ai.dir/ai_monster.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_monster.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_monster.c > CMakeFiles/ai.dir/ai_monster.c.i

src/ai/CMakeFiles/ai.dir/ai_monster.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_monster.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_monster.c -o CMakeFiles/ai.dir/ai_monster.c.s

src/ai/CMakeFiles/ai.dir/ai_monster.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_monster.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_monster.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_monster.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_monster.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_monster.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_monster.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_monster.c.o


src/ai/CMakeFiles/ai.dir/ai_piece.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_piece.c.o: ../src/ai/ai_piece.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/ai/CMakeFiles/ai.dir/ai_piece.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_piece.c.o   -c /home/bigfoot/bomberman/src/ai/ai_piece.c

src/ai/CMakeFiles/ai.dir/ai_piece.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_piece.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_piece.c > CMakeFiles/ai.dir/ai_piece.c.i

src/ai/CMakeFiles/ai.dir/ai_piece.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_piece.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_piece.c -o CMakeFiles/ai.dir/ai_piece.c.s

src/ai/CMakeFiles/ai.dir/ai_piece.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_piece.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_piece.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_piece.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_piece.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_piece.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_piece.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_piece.c.o


src/ai/CMakeFiles/ai.dir/ai_msg.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_msg.c.o: ../src/ai/ai_msg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/ai/CMakeFiles/ai.dir/ai_msg.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_msg.c.o   -c /home/bigfoot/bomberman/src/ai/ai_msg.c

src/ai/CMakeFiles/ai.dir/ai_msg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_msg.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_msg.c > CMakeFiles/ai.dir/ai_msg.c.i

src/ai/CMakeFiles/ai.dir/ai_msg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_msg.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_msg.c -o CMakeFiles/ai.dir/ai_msg.c.s

src/ai/CMakeFiles/ai.dir/ai_msg.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_msg.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_msg.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_msg.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_msg.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_msg.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_msg.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_msg.c.o


src/ai/CMakeFiles/ai.dir/ai_timer.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/ai_timer.c.o: ../src/ai/ai_timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/ai/CMakeFiles/ai.dir/ai_timer.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/ai_timer.c.o   -c /home/bigfoot/bomberman/src/ai/ai_timer.c

src/ai/CMakeFiles/ai.dir/ai_timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/ai_timer.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/ai_timer.c > CMakeFiles/ai.dir/ai_timer.c.i

src/ai/CMakeFiles/ai.dir/ai_timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/ai_timer.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/ai_timer.c -o CMakeFiles/ai.dir/ai_timer.c.s

src/ai/CMakeFiles/ai.dir/ai_timer.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/ai_timer.c.o.requires

src/ai/CMakeFiles/ai.dir/ai_timer.c.o.provides: src/ai/CMakeFiles/ai.dir/ai_timer.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/ai_timer.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/ai_timer.c.o.provides

src/ai/CMakeFiles/ai.dir/ai_timer.c.o.provides.build: src/ai/CMakeFiles/ai.dir/ai_timer.c.o


src/ai/CMakeFiles/ai.dir/sprites.c.o: src/ai/CMakeFiles/ai.dir/flags.make
src/ai/CMakeFiles/ai.dir/sprites.c.o: ../src/ai/sprites.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/ai/CMakeFiles/ai.dir/sprites.c.o"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ai.dir/sprites.c.o   -c /home/bigfoot/bomberman/src/ai/sprites.c

src/ai/CMakeFiles/ai.dir/sprites.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ai.dir/sprites.c.i"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bigfoot/bomberman/src/ai/sprites.c > CMakeFiles/ai.dir/sprites.c.i

src/ai/CMakeFiles/ai.dir/sprites.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ai.dir/sprites.c.s"
	cd /home/bigfoot/bomberman/build/src/ai && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bigfoot/bomberman/src/ai/sprites.c -o CMakeFiles/ai.dir/sprites.c.s

src/ai/CMakeFiles/ai.dir/sprites.c.o.requires:

.PHONY : src/ai/CMakeFiles/ai.dir/sprites.c.o.requires

src/ai/CMakeFiles/ai.dir/sprites.c.o.provides: src/ai/CMakeFiles/ai.dir/sprites.c.o.requires
	$(MAKE) -f src/ai/CMakeFiles/ai.dir/build.make src/ai/CMakeFiles/ai.dir/sprites.c.o.provides.build
.PHONY : src/ai/CMakeFiles/ai.dir/sprites.c.o.provides

src/ai/CMakeFiles/ai.dir/sprites.c.o.provides.build: src/ai/CMakeFiles/ai.dir/sprites.c.o


# Object files for target ai
ai_OBJECTS = \
"CMakeFiles/ai.dir/ai.c.o" \
"CMakeFiles/ai.dir/ai_bomb.c.o" \
"CMakeFiles/ai.dir/ai_bonus_penalty.c.o" \
"CMakeFiles/ai.dir/ai_counter.c.o" \
"CMakeFiles/ai.dir/ai_dead.c.o" \
"CMakeFiles/ai.dir/ai_blast.c.o" \
"CMakeFiles/ai.dir/ai_map.c.o" \
"CMakeFiles/ai.dir/ai_monster.c.o" \
"CMakeFiles/ai.dir/ai_piece.c.o" \
"CMakeFiles/ai.dir/ai_msg.c.o" \
"CMakeFiles/ai.dir/ai_timer.c.o" \
"CMakeFiles/ai.dir/sprites.c.o"

# External object files for target ai
ai_EXTERNAL_OBJECTS =

src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_bomb.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_counter.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_dead.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_blast.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_map.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_monster.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_piece.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_msg.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/ai_timer.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/sprites.c.o
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/build.make
src/ai/libai.so: src/ai/CMakeFiles/ai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigfoot/bomberman/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C shared library libai.so"
	cd /home/bigfoot/bomberman/build/src/ai && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ai.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/ai/CMakeFiles/ai.dir/build: src/ai/libai.so

.PHONY : src/ai/CMakeFiles/ai.dir/build

src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_bomb.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_bonus_penalty.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_counter.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_dead.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_blast.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_map.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_monster.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_piece.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_msg.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/ai_timer.c.o.requires
src/ai/CMakeFiles/ai.dir/requires: src/ai/CMakeFiles/ai.dir/sprites.c.o.requires

.PHONY : src/ai/CMakeFiles/ai.dir/requires

src/ai/CMakeFiles/ai.dir/clean:
	cd /home/bigfoot/bomberman/build/src/ai && $(CMAKE_COMMAND) -P CMakeFiles/ai.dir/cmake_clean.cmake
.PHONY : src/ai/CMakeFiles/ai.dir/clean

src/ai/CMakeFiles/ai.dir/depend:
	cd /home/bigfoot/bomberman/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigfoot/bomberman /home/bigfoot/bomberman/src/ai /home/bigfoot/bomberman/build /home/bigfoot/bomberman/build/src/ai /home/bigfoot/bomberman/build/src/ai/CMakeFiles/ai.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/ai/CMakeFiles/ai.dir/depend

