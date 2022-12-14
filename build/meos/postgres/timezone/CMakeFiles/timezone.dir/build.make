# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/mariana/MobilityDB-Smoothing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariana/MobilityDB-Smoothing/build

# Include any dependencies generated for this target.
include meos/postgres/timezone/CMakeFiles/timezone.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include meos/postgres/timezone/CMakeFiles/timezone.dir/compiler_depend.make

# Include the progress variables for this target.
include meos/postgres/timezone/CMakeFiles/timezone.dir/progress.make

# Include the compile flags for this target's objects.
include meos/postgres/timezone/CMakeFiles/timezone.dir/flags.make

meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.o: meos/postgres/timezone/CMakeFiles/timezone.dir/flags.make
meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.o: ../meos/postgres/timezone/findtimezone.c
meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.o: meos/postgres/timezone/CMakeFiles/timezone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/MobilityDB-Smoothing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.o"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.o -MF CMakeFiles/timezone.dir/findtimezone.c.o.d -o CMakeFiles/timezone.dir/findtimezone.c.o -c /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/findtimezone.c

meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timezone.dir/findtimezone.c.i"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/findtimezone.c > CMakeFiles/timezone.dir/findtimezone.c.i

meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timezone.dir/findtimezone.c.s"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/findtimezone.c -o CMakeFiles/timezone.dir/findtimezone.c.s

meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.o: meos/postgres/timezone/CMakeFiles/timezone.dir/flags.make
meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.o: ../meos/postgres/timezone/localtime.c
meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.o: meos/postgres/timezone/CMakeFiles/timezone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/MobilityDB-Smoothing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.o"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.o -MF CMakeFiles/timezone.dir/localtime.c.o.d -o CMakeFiles/timezone.dir/localtime.c.o -c /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/localtime.c

meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timezone.dir/localtime.c.i"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/localtime.c > CMakeFiles/timezone.dir/localtime.c.i

meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timezone.dir/localtime.c.s"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/localtime.c -o CMakeFiles/timezone.dir/localtime.c.s

meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.o: meos/postgres/timezone/CMakeFiles/timezone.dir/flags.make
meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.o: ../meos/postgres/timezone/pgtz.c
meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.o: meos/postgres/timezone/CMakeFiles/timezone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariana/MobilityDB-Smoothing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.o"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.o -MF CMakeFiles/timezone.dir/pgtz.c.o.d -o CMakeFiles/timezone.dir/pgtz.c.o -c /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/pgtz.c

meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timezone.dir/pgtz.c.i"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/pgtz.c > CMakeFiles/timezone.dir/pgtz.c.i

meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timezone.dir/pgtz.c.s"
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone/pgtz.c -o CMakeFiles/timezone.dir/pgtz.c.s

timezone: meos/postgres/timezone/CMakeFiles/timezone.dir/findtimezone.c.o
timezone: meos/postgres/timezone/CMakeFiles/timezone.dir/localtime.c.o
timezone: meos/postgres/timezone/CMakeFiles/timezone.dir/pgtz.c.o
timezone: meos/postgres/timezone/CMakeFiles/timezone.dir/build.make
.PHONY : timezone

# Rule to build all files generated by this target.
meos/postgres/timezone/CMakeFiles/timezone.dir/build: timezone
.PHONY : meos/postgres/timezone/CMakeFiles/timezone.dir/build

meos/postgres/timezone/CMakeFiles/timezone.dir/clean:
	cd /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone && $(CMAKE_COMMAND) -P CMakeFiles/timezone.dir/cmake_clean.cmake
.PHONY : meos/postgres/timezone/CMakeFiles/timezone.dir/clean

meos/postgres/timezone/CMakeFiles/timezone.dir/depend:
	cd /home/mariana/MobilityDB-Smoothing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariana/MobilityDB-Smoothing /home/mariana/MobilityDB-Smoothing/meos/postgres/timezone /home/mariana/MobilityDB-Smoothing/build /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone /home/mariana/MobilityDB-Smoothing/build/meos/postgres/timezone/CMakeFiles/timezone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : meos/postgres/timezone/CMakeFiles/timezone.dir/depend

