*This project has been created as part of the 42 curriculum by  <boadopo>.*


# Sommaire

- [1. Introduction](#1-introduction)
- [2. Description](#2-description)
- [3. Instructions](#3-instructions)
- [4. Resources](#4-resources)

# 1. Introduction

A school project designed to help learn, manipulate, and properly understand pointers, structures, `malloc`, linked lists, header files, Makefiles, and more.
This project is implemented in the C programming language.



# Description

libft is the first project of the 42 curriculum. The goal is to recode, in C, a set of standard library functions, then to add useful extra functions, and to gather everything in a static library (libft.a) that can be reused in all future 42 projects.

The library is split in three parts:

#### Part 1 - libc functions: re-implementation of standard functions, prefixed with ft_.

Character checks :	ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
Character conversion :	ft_toupper, ft_tolower
Strings	ft_strlen, ft_strlcpy, ft_strlcat, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strdup
Memory : ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp, ft_calloc
Conversion	ft_atoi

#### Part 2 - additional functions: utilities that are not in the libc, or exist in a different form.

Function	Description
ft_substr	Returns a substring of a string.
ft_strjoin	Concatenates two strings into a new one.
ft_strtrim	Trims a set of characters from both ends of a string.
ft_split	Splits a string using a delimiter character.
ft_itoa	Converts an integer to a string.
ft_strmapi	Applies a function to each character and returns the new string.
ft_striteri	Applies a function to each character (with its index).
ft_putchar_fd	Writes a character to a file descriptor.
ft_putstr_fd	Writes a string to a file descriptor.
ft_putendl_fd	Writes a string followed by a newline to a file descriptor.
ft_putnbr_fd	Writes an integer to a file descriptor.


#### Part 3 - linked lists: basic functions to manipulate singly linked lists.

Functions working on the t_list structure:

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back, ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap.


# Instructions

## Requirements

The code follows the 42 Norm and is compiled with -Wall -Wextra -Werror.

### Compilation

make          # builds libft.a (mandatory part)
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all

### Usage

Include the header in your source file:

#include "libft.h"

Then compile your program and link it with the library:

cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

Example:

#include "libft.h"

int	main(void)
{
	char	*s;

	s = ft_strdup("hello");
	if (!s)
		return (1);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}

# Resources

## References

man pages of the reimplemented functions (man strlcpy, man calloc, ...).

The 42 Norm - coding style rules checked by norminette.

Use of AI : AI was used as a  to understand concepts (signed vs unsigned types and casts, size_t overflow in calloc, strdup memory layout), to help write this README.
