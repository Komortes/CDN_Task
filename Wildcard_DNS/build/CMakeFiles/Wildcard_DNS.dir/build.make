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
CMAKE_SOURCE_DIR = /home/komortes/code/CDN_Task/Wildcard_DNS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/komortes/code/CDN_Task/Wildcard_DNS/build

# Include any dependencies generated for this target.
include CMakeFiles/Wildcard_DNS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Wildcard_DNS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Wildcard_DNS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Wildcard_DNS.dir/flags.make

CMakeFiles/Wildcard_DNS.dir/3_task.c.o: CMakeFiles/Wildcard_DNS.dir/flags.make
CMakeFiles/Wildcard_DNS.dir/3_task.c.o: /home/komortes/code/CDN_Task/Wildcard_DNS/src/3_task.c
CMakeFiles/Wildcard_DNS.dir/3_task.c.o: CMakeFiles/Wildcard_DNS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komortes/code/CDN_Task/Wildcard_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Wildcard_DNS.dir/3_task.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Wildcard_DNS.dir/3_task.c.o -MF CMakeFiles/Wildcard_DNS.dir/3_task.c.o.d -o CMakeFiles/Wildcard_DNS.dir/3_task.c.o -c /home/komortes/code/CDN_Task/Wildcard_DNS/src/3_task.c

CMakeFiles/Wildcard_DNS.dir/3_task.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wildcard_DNS.dir/3_task.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komortes/code/CDN_Task/Wildcard_DNS/src/3_task.c > CMakeFiles/Wildcard_DNS.dir/3_task.c.i

CMakeFiles/Wildcard_DNS.dir/3_task.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wildcard_DNS.dir/3_task.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komortes/code/CDN_Task/Wildcard_DNS/src/3_task.c -o CMakeFiles/Wildcard_DNS.dir/3_task.c.s

CMakeFiles/Wildcard_DNS.dir/Trie.c.o: CMakeFiles/Wildcard_DNS.dir/flags.make
CMakeFiles/Wildcard_DNS.dir/Trie.c.o: /home/komortes/code/CDN_Task/Wildcard_DNS/src/Trie.c
CMakeFiles/Wildcard_DNS.dir/Trie.c.o: CMakeFiles/Wildcard_DNS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komortes/code/CDN_Task/Wildcard_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Wildcard_DNS.dir/Trie.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Wildcard_DNS.dir/Trie.c.o -MF CMakeFiles/Wildcard_DNS.dir/Trie.c.o.d -o CMakeFiles/Wildcard_DNS.dir/Trie.c.o -c /home/komortes/code/CDN_Task/Wildcard_DNS/src/Trie.c

CMakeFiles/Wildcard_DNS.dir/Trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Wildcard_DNS.dir/Trie.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komortes/code/CDN_Task/Wildcard_DNS/src/Trie.c > CMakeFiles/Wildcard_DNS.dir/Trie.c.i

CMakeFiles/Wildcard_DNS.dir/Trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Wildcard_DNS.dir/Trie.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komortes/code/CDN_Task/Wildcard_DNS/src/Trie.c -o CMakeFiles/Wildcard_DNS.dir/Trie.c.s

# Object files for target Wildcard_DNS
Wildcard_DNS_OBJECTS = \
"CMakeFiles/Wildcard_DNS.dir/3_task.c.o" \
"CMakeFiles/Wildcard_DNS.dir/Trie.c.o"

# External object files for target Wildcard_DNS
Wildcard_DNS_EXTERNAL_OBJECTS =

Wildcard_DNS: CMakeFiles/Wildcard_DNS.dir/3_task.c.o
Wildcard_DNS: CMakeFiles/Wildcard_DNS.dir/Trie.c.o
Wildcard_DNS: CMakeFiles/Wildcard_DNS.dir/build.make
Wildcard_DNS: CMakeFiles/Wildcard_DNS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/komortes/code/CDN_Task/Wildcard_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Wildcard_DNS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Wildcard_DNS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Wildcard_DNS.dir/build: Wildcard_DNS
.PHONY : CMakeFiles/Wildcard_DNS.dir/build

CMakeFiles/Wildcard_DNS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Wildcard_DNS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Wildcard_DNS.dir/clean

CMakeFiles/Wildcard_DNS.dir/depend:
	cd /home/komortes/code/CDN_Task/Wildcard_DNS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/komortes/code/CDN_Task/Wildcard_DNS/src /home/komortes/code/CDN_Task/Wildcard_DNS/src /home/komortes/code/CDN_Task/Wildcard_DNS/build /home/komortes/code/CDN_Task/Wildcard_DNS/build /home/komortes/code/CDN_Task/Wildcard_DNS/build/CMakeFiles/Wildcard_DNS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Wildcard_DNS.dir/depend

