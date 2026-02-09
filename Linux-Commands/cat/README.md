# Cat Implementation by me (C)

A robust implementation of the Unix `cat` command, built to demonstrate **Linux System Calls** and **Buffer Management**.

##  Key Features
 **Low-Level I/O:** Uses `open()`, `read()`, and `write()` directly from the kernel, bypassing standard streams (`<stdio.h>`).
 **Memory Efficient:** Reads files in chunks (4KB buffer) rather than loading the entire file into RAM.
 **Error Handling:** Correctly directs error messages to **Standard Error (stderr / fd 2)**, keeping stdout clean for piping.

## Compilation

```bash
gcc main.c -o x
