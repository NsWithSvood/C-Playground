#  my_ls - Custom LS Implementation

This project recreates the core functionality of the standard UNIX `ls` command using C.

The primary goal is to master file system interactions, system calls, and manual dynamic memory management without relying on fixed-size buffers.

##  Features

- **Dynamic Memory Allocation:** Utilizes `malloc` and `realloc` to handle an arbitrary number of files, creating a fully expandable list structure.
- **System Calls:** Direct interaction with the Linux kernel using `<dirent.h>` (`opendir`, `readdir`, `closedir`).
- **Memory Safety:** Implements a full cleanup routine (`free`) to ensure zero memory leaks upon exit.
- **Deep Copying:** Safely copies volatile `d_name` strings into persistent heap memory.

##  Build & Run

Requires a GCC compiler.

```bash
# Compile
gcc main.c -o ls1

# Run (Lists current directory)
./ls1
