
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SOURCES = \
	ft_strlen.c \
	ft_strncmp.c \
	ft_calloc.c \
	ft_substr.c \
	ft_split.c \
	ft_putnbr_fd.c \
	ft_putchar_fd.c \
	ft_memcpy.c \
	ft_putstr_fd.c


OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

