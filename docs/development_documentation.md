<!--
Copyright (c) 2026 Richard Varela
This file is part of Progex which is release under 3-Clause BSD.
See LICENSE for details.
-->

**Table of Contents**

- [Introduction](#introduction)
- [Conventions](#conventions)
	- [Style](#style)
	- [Source File Locations](#source-file-locations)
- [Design](#design)
	- [Hierarchy Chart](#hierarchy-chart)
	- [Flowchart](#flowchart)
- [Build Guide](#build-guide)
	- [Debug](#debug)
	- [Clean Up](#clean-up)

- - -

# Introduction

This document contains all information related to developing Progex, covering conventions, design, and building.

# Conventions

The following sections go over the project's conventions related to style and source file placements.

## Style

The following are the styling guidelines for the source files:

- Snake case is used for function and variable names.
- Verbs are used for functions.
- Nouns are used for variables and constants.
- The source file name should match the function name, unless the source file name is for a collection of functions.
- Instead of writing multiple `printf` statements for each unique line, utilize C's string concatenation.
- Use K&R style for brace placement.
- Use comments when you can express clearly in code.

## Source File Locations

The following show the directory structure.

```text
progex/
|--build/
|--docs/
|  |--development_documentation.md
|  |--manual.md
|--include/
|  |--All header files
|--src/
|  |--All source files
|--tests/
|--makefile
```

# Design

## Hierarchy Chart

The following shows the hierarchy of Progex's functions.

```mermaid
flowchart TD;
m[main]
h[help_info]
v[version_version]
chk_dir_err[check_mkdir_error]
c[create_c_project]
j[create_java_project]
p[create_python_project]
gen_files[generate_files]
gen_dirs[generate_directories]

m --> h
m --> v
m --> c
c --> gen_files
c --> gen_dirs
m --> j
j --> gen_files
j --> gen_dirs
m --> p
p --> gen_files
p --> gen_dirs
gen_dirs --> chk_dir_err

```

## Flowchart

The following flowchart shows the application's logical flow.

```mermaid
flowchart TD;

s@{ shape: sm-circ, label: "Start" }
e@{ shape: framed-circle, label: "End" }
proc[Process commandline arguments]
action@{ shape: diamond, label: "Do what?" }
help[Show help info]
version[Show version info]
create[Create project]
create_dirs@{ shape: diamond, label: "All directories made?" }
create_files@{ shape: diamond, label: "All files made?" }
err_dir@{ shape: diamond, label: "Error making directory?" }
report_dir_err[Report directory could not be made]
mk_dir[Make directory]
err_file@{ shape: diamond, label: "Erro making directory?" }
mk_file[Make file]
report_file_err[Report file could not be made]
funcs[Call appropriate function for language type]

s --> proc
proc --> action
action --> help
action --> version
action --> create
help --> e
version --> e
create --> funcs
funcs --> create_dirs
create_dirs -- No --> mk_dir
create_dirs -- Yes --> create_files
mk_dir --> err_dir
err_dir -- Yes --> report_dir_err
err_dir -- No --> create_dirs
report_dir_err --> create_dirs
create_files -- No --> mk_file
mk_file --> err_file
err_file -- No --> create_files
err_file -- Yes --> report_file_err
report_file_err --> create_files
create_files -- Yes --> e
```

# Build Guide

To build the Progex, simple run `make`.
This will run the following in the `makefile`:

```makefile
default: $(OBJFILES)
        gcc -Wall $(OBJFILES) -o ./build/a.exe
```

where `$(OBJFILES)` represents all objects files made by the compiler.

## Debug

To debug, run `make debug` to compiler the entire application with debugging information.
This will also start GDB.

## Cleaning Up

To clean up object files and the compiled program for whatever reason, just simple run `make clean`.
