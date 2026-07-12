**Table of Contents**

- [Usage](#usage)
	- [Building a Simple Project](#building-a-simple-project)
- [Build Instructions](#build-instructions)

- - -

# Usage

## Building a Simple Project

To create a new project, simple provide the programming language *first*, and the name of your new project *second*.

```bash
progex <language> <project name>
```

**Ex:**

```bash
progex c My_C_Project
```

*Note:* The language argument is not case sensitive.
Progex will convert the language argument to lower case, no matter what.
Your project name, however, is case sensitive, and the main directory created will use your exact spelling and casing.

To get help from the command-line, use `--help`.

```bash
progex --help
```

# Build Instructions

This application requires no dependencies.
You should be able to build it with any C compiler, and have a Make utility (like GNU Make for example).

To build, simple run `make` and it will build the entire application.
This will produce an executable called `progex` in the `build/` directory.

*Note:* On Windows, specifically using MSYS2, it will be `progex.exe` instead.
