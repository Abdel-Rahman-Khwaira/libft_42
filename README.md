*This project has been created as part of the 42 curriculum by akhwaira.*

# libft

A C library that re-implements standard libc functions and adds extra utilities for linked lists, strings, and file descriptor output.

## Description

Libft is the first project of the 42 curriculum. The goal is to write my own C library from scratch, without using the standard library for the core logic. The library is then reused in later 42 projects.

The project taught me how memory, strings, and pointers work in C, and how to write clean code that follows the 42 Norm.

All functions are prefixed with `ft_` (for example, `ft_strlen`) and are compiled into a static library, `libft.a`.

### Overview of the functions

| Part | Functions |
|------|-----------|
| **Libc functions** | `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `strlen`, `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`, `strchr`, `strrchr`, `strncmp`, `strlcpy`, `strlcat`, `strnstr`, `atoi`, `calloc`, `strdup` |
| **Additional functions** | `substr`, `strjoin`, `strtrim`, `split`, `itoa`, `strmapi`, `striteri`, `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd` |
| **Linked list functions** | `lstnew`, `lstadd_front`, `lstsize`, `lstlast`, `lstadd_back`, `lstdelone`, `lstclear`, `lstiter`, `lstmap` |

## Instructions

### Compilation

Clone the repository and run `make` in the root folder:

```bash
git clone <your-repo-url> libft
cd libft
make
```

This creates the static library `libft.a`.

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles the library into `libft.a` |
| `make clean` | Removes the object files |
| `make fclean` | Removes the object files and `libft.a` |
| `make re` | Runs `fclean`, then `all` |

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Compile your program and link it with the library:

```bash
cc -Wall -Wextra -Werror your_program.c -L. -lft -o program_output
```

Then run it:

```bash
./program_output
```

## Resources

### References

- `PeerToPeer Learing` the best way to learn
- [Linux man pages](https://man7.org/linux/man-pages/): reference for the libc functions
- `man` page on terminal
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/)
- *The C Programming Language* by Kernighan and Ritchie
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/)
- [The 42 Norm](https://github.com/42School/norminette)

### Use of AI

AI was used as a learning and support tool, not to write the project for me.
 
- **README:** helping me structure this file

All the code was written by me, and I can explain every function in the project.

> "At the end I appreciate your effort to read"