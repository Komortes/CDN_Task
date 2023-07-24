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
CMAKE_SOURCE_DIR = /home/komortes/code/CDN_Task/CDN_DNS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/komortes/code/CDN_Task/CDN_DNS/build

# Include any dependencies generated for this target.
include CMakeFiles/CDN_DNS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CDN_DNS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CDN_DNS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CDN_DNS.dir/flags.make

CMakeFiles/CDN_DNS.dir/dns.c.o: CMakeFiles/CDN_DNS.dir/flags.make
CMakeFiles/CDN_DNS.dir/dns.c.o: /home/komortes/code/CDN_Task/CDN_DNS/src/dns.c
CMakeFiles/CDN_DNS.dir/dns.c.o: CMakeFiles/CDN_DNS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komortes/code/CDN_Task/CDN_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CDN_DNS.dir/dns.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CDN_DNS.dir/dns.c.o -MF CMakeFiles/CDN_DNS.dir/dns.c.o.d -o CMakeFiles/CDN_DNS.dir/dns.c.o -c /home/komortes/code/CDN_Task/CDN_DNS/src/dns.c

CMakeFiles/CDN_DNS.dir/dns.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CDN_DNS.dir/dns.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komortes/code/CDN_Task/CDN_DNS/src/dns.c > CMakeFiles/CDN_DNS.dir/dns.c.i

CMakeFiles/CDN_DNS.dir/dns.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CDN_DNS.dir/dns.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komortes/code/CDN_Task/CDN_DNS/src/dns.c -o CMakeFiles/CDN_DNS.dir/dns.c.s

CMakeFiles/CDN_DNS.dir/Reader.c.o: CMakeFiles/CDN_DNS.dir/flags.make
CMakeFiles/CDN_DNS.dir/Reader.c.o: /home/komortes/code/CDN_Task/CDN_DNS/src/Reader.c
CMakeFiles/CDN_DNS.dir/Reader.c.o: CMakeFiles/CDN_DNS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komortes/code/CDN_Task/CDN_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CDN_DNS.dir/Reader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CDN_DNS.dir/Reader.c.o -MF CMakeFiles/CDN_DNS.dir/Reader.c.o.d -o CMakeFiles/CDN_DNS.dir/Reader.c.o -c /home/komortes/code/CDN_Task/CDN_DNS/src/Reader.c

CMakeFiles/CDN_DNS.dir/Reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CDN_DNS.dir/Reader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komortes/code/CDN_Task/CDN_DNS/src/Reader.c > CMakeFiles/CDN_DNS.dir/Reader.c.i

CMakeFiles/CDN_DNS.dir/Reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CDN_DNS.dir/Reader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komortes/code/CDN_Task/CDN_DNS/src/Reader.c -o CMakeFiles/CDN_DNS.dir/Reader.c.s

CMakeFiles/CDN_DNS.dir/Trie.c.o: CMakeFiles/CDN_DNS.dir/flags.make
CMakeFiles/CDN_DNS.dir/Trie.c.o: /home/komortes/code/CDN_Task/CDN_DNS/src/Trie.c
CMakeFiles/CDN_DNS.dir/Trie.c.o: CMakeFiles/CDN_DNS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/komortes/code/CDN_Task/CDN_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CDN_DNS.dir/Trie.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/CDN_DNS.dir/Trie.c.o -MF CMakeFiles/CDN_DNS.dir/Trie.c.o.d -o CMakeFiles/CDN_DNS.dir/Trie.c.o -c /home/komortes/code/CDN_Task/CDN_DNS/src/Trie.c

CMakeFiles/CDN_DNS.dir/Trie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CDN_DNS.dir/Trie.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/komortes/code/CDN_Task/CDN_DNS/src/Trie.c > CMakeFiles/CDN_DNS.dir/Trie.c.i

CMakeFiles/CDN_DNS.dir/Trie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CDN_DNS.dir/Trie.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/komortes/code/CDN_Task/CDN_DNS/src/Trie.c -o CMakeFiles/CDN_DNS.dir/Trie.c.s

# Object files for target CDN_DNS
CDN_DNS_OBJECTS = \
"CMakeFiles/CDN_DNS.dir/dns.c.o" \
"CMakeFiles/CDN_DNS.dir/Reader.c.o" \
"CMakeFiles/CDN_DNS.dir/Trie.c.o"

# External object files for target CDN_DNS
CDN_DNS_EXTERNAL_OBJECTS =

CDN_DNS: CMakeFiles/CDN_DNS.dir/dns.c.o
CDN_DNS: CMakeFiles/CDN_DNS.dir/Reader.c.o
CDN_DNS: CMakeFiles/CDN_DNS.dir/Trie.c.o
CDN_DNS: CMakeFiles/CDN_DNS.dir/build.make
CDN_DNS: CMakeFiles/CDN_DNS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/komortes/code/CDN_Task/CDN_DNS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable CDN_DNS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CDN_DNS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CDN_DNS.dir/build: CDN_DNS
.PHONY : CMakeFiles/CDN_DNS.dir/build

CMakeFiles/CDN_DNS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CDN_DNS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CDN_DNS.dir/clean

CMakeFiles/CDN_DNS.dir/depend:
	cd /home/komortes/code/CDN_Task/CDN_DNS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/komortes/code/CDN_Task/CDN_DNS/src /home/komortes/code/CDN_Task/CDN_DNS/src /home/komortes/code/CDN_Task/CDN_DNS/build /home/komortes/code/CDN_Task/CDN_DNS/build /home/komortes/code/CDN_Task/CDN_DNS/build/CMakeFiles/CDN_DNS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CDN_DNS.dir/depend

