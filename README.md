# Custom Shell

## Overview
This is a simple custom shell written in C++ from scratch. It supports various shell-like features including command execution, piping, background processes, and I/O redirection.

## Features
- **Execute Commands**: Run standard system commands.
- **Change Directory (`cd`)**: Navigate between directories.
- **Help Command (`help`)**: Display available commands.
- **Background Execution (`&`)**: Run processes in the background.
- **Check Background Processes (`checkbg`)**: View running background jobs.
- **Piping (`|`)**: Connect commands using pipes.
- **I/O Redirection (`>` and `>>`)**: Redirect command output to files.

## Installation & Compilation
### Prerequisites
- C++ Compiler (G++ recommended)
- Make (for compilation automation)

### Build Instructions
To compile the shell, use the provided **Makefile**:
```sh
make
```
This generates the executable `shell`.

### Running the Shell
After compilation, run the shell with:
```sh
./shell
```

### Cleaning Up
To remove compiled files, run:
```sh
make clean
```

## Usage
### Running Commands
You can run any system command just like in a normal shell:
```sh
ls
pwd
echo "Hello, World!"
```

### Changing Directories
```sh
cd <directory>
```
Example:
```sh
cd /home/user
```

### Background Execution
Run a command in the background by appending `&`:
```sh
top &
```
Use `checkbg` to view background processes:
```sh
checkbg
```

### Piping Commands
Use `|` to pass the output of one command as input to another:
```sh
ls | grep .cpp
```

### I/O Redirection
- Overwrite file output:
  ```sh
  echo "Hello" > file.txt
  ```
- Append to a file:
  ```sh
  echo "Hello Again" >> file.txt
  ```

### Display Help
Run:
```sh
help
```

