# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /class/classes/jmari016/assignment-rshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /class/classes/jmari016/assignment-rshell

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /class/classes/jmari016/assignment-rshell/CMakeFiles /class/classes/jmari016/assignment-rshell/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /class/classes/jmari016/assignment-rshell/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named rshell

# Build rule for target.
rshell: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 rshell
.PHONY : rshell

# fast build rule for target.
rshell/fast:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/build
.PHONY : rshell/fast

src/Execute.o: src/Execute.cpp.o

.PHONY : src/Execute.o

# target to build an object file
src/Execute.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Execute.cpp.o
.PHONY : src/Execute.cpp.o

src/Execute.i: src/Execute.cpp.i

.PHONY : src/Execute.i

# target to preprocess a source file
src/Execute.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Execute.cpp.i
.PHONY : src/Execute.cpp.i

src/Execute.s: src/Execute.cpp.s

.PHONY : src/Execute.s

# target to generate assembly for a file
src/Execute.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Execute.cpp.s
.PHONY : src/Execute.cpp.s

src/ExecuteAND.o: src/ExecuteAND.cpp.o

.PHONY : src/ExecuteAND.o

# target to build an object file
src/ExecuteAND.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o
.PHONY : src/ExecuteAND.cpp.o

src/ExecuteAND.i: src/ExecuteAND.cpp.i

.PHONY : src/ExecuteAND.i

# target to preprocess a source file
src/ExecuteAND.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteAND.cpp.i
.PHONY : src/ExecuteAND.cpp.i

src/ExecuteAND.s: src/ExecuteAND.cpp.s

.PHONY : src/ExecuteAND.s

# target to generate assembly for a file
src/ExecuteAND.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteAND.cpp.s
.PHONY : src/ExecuteAND.cpp.s

src/ExecuteOR.o: src/ExecuteOR.cpp.o

.PHONY : src/ExecuteOR.o

# target to build an object file
src/ExecuteOR.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o
.PHONY : src/ExecuteOR.cpp.o

src/ExecuteOR.i: src/ExecuteOR.cpp.i

.PHONY : src/ExecuteOR.i

# target to preprocess a source file
src/ExecuteOR.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteOR.cpp.i
.PHONY : src/ExecuteOR.cpp.i

src/ExecuteOR.s: src/ExecuteOR.cpp.s

.PHONY : src/ExecuteOR.s

# target to generate assembly for a file
src/ExecuteOR.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteOR.cpp.s
.PHONY : src/ExecuteOR.cpp.s

src/ExecuteSEMI.o: src/ExecuteSEMI.cpp.o

.PHONY : src/ExecuteSEMI.o

# target to build an object file
src/ExecuteSEMI.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o
.PHONY : src/ExecuteSEMI.cpp.o

src/ExecuteSEMI.i: src/ExecuteSEMI.cpp.i

.PHONY : src/ExecuteSEMI.i

# target to preprocess a source file
src/ExecuteSEMI.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.i
.PHONY : src/ExecuteSEMI.cpp.i

src/ExecuteSEMI.s: src/ExecuteSEMI.cpp.s

.PHONY : src/ExecuteSEMI.s

# target to generate assembly for a file
src/ExecuteSEMI.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.s
.PHONY : src/ExecuteSEMI.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... rshell"
	@echo "... src/Execute.o"
	@echo "... src/Execute.i"
	@echo "... src/Execute.s"
	@echo "... src/ExecuteAND.o"
	@echo "... src/ExecuteAND.i"
	@echo "... src/ExecuteAND.s"
	@echo "... src/ExecuteOR.o"
	@echo "... src/ExecuteOR.i"
	@echo "... src/ExecuteOR.s"
	@echo "... src/ExecuteSEMI.o"
	@echo "... src/ExecuteSEMI.i"
	@echo "... src/ExecuteSEMI.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

