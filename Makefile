CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Iincludes -g

NAME    = push_swap
BONUS   = checker
LIBFT   = ./libft/libft.a

SRCS = \
	srcs/algos/rotate_to_top.c \
	srcs/algos/sort_complex.c \
	srcs/algos/sort_medium.c \
	srcs/algos/sort_simple.c \
	srcs/algos/sort_small.c \
	srcs/algos/strategy.c \
	srcs/analysis/disorder.c \
	srcs/analysis/normalize.c \
	srcs/bench/bench.c \
	srcs/ops/ops_log.c \
	srcs/ops/ops_push.c \
	srcs/ops/ops_rev_rotate.c \
	srcs/ops/ops_rotate.c \
	srcs/ops/ops_swap.c \
	srcs/parsing/ft_split_by_spaces.c \
	srcs/parsing/init_ctx.c \
	srcs/parsing/parse_args.c \
	srcs/parsing/parse_utils_bis.c \
	srcs/parsing/parse_utils.c \
	srcs/stack/stack_basic.c \
	srcs/stack/stack_find.c \
	srcs/stack/stack_ops.c 

CHECKER_SRCS = \
	the_checker/ft_realloc.c \
	the_checker/ops_push_checker.c \
	the_checker/ops_rev_rotate_checker.c \
	the_checker/ops_rotate_checker.c \
	the_checker/ops_swap_checker.c\
	the_checker/checker.c

MAIN = main.c
OBJS         = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
MAIN_OBJ = $(MAIN:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(OBJS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) $(LIBFT) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CHECKER_OBJS) $(MAIN_OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re