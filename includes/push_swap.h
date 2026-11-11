#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef enum e_op { SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR }	t_op;

typedef enum e_strat { ADAPTIVE, SIMPLE, MEDIUM, COMPLEX }	t_strat;

typedef struct s_ctx
{
	t_node		*a;
	t_node		*b;
	int			count[11];
	int			total;
	int			bench;
	t_strat		strat;
	double		disorder;
	const char	*name;
	const char	*cplx;
	const char	*op_names[11];
}	t_ctx;

void	init_ctx(t_ctx *c);
int		error_exit(t_ctx *c);
void	init_ops(t_ctx *c);
void	swap_case(t_node **s);
void	push_top(t_node **from, t_node **to);
void	rotate_up(t_node **s);
void	rotate_down(t_node **s);
void	log_op(t_ctx *c, t_op op);
int		ft_atoi_safe(const char *s, int *out);
int		parse_option(t_ctx *c, char *arg);
int		add_back(t_node **a, int value);
int		has_duplicate(t_node *a);
int		parse_args(t_ctx *c, int argc, char **argv);
void	free_stack(t_node **s);
int		stack_size(t_node *s);
void	print_stack(t_node *stack);
int		is_sorted(t_node *a);
void	sa(t_ctx *c);
void	sb(t_ctx *c);
void	pa(t_ctx *c);
void	pb(t_ctx *c);
void	ra(t_ctx *c);
void	rb(t_ctx *c);
void	rr(t_ctx *c);
void	rra(t_ctx *c);
void	rrb(t_ctx *c);
void	rr(t_ctx *c);
void	rot_a_to_top(t_ctx *c, int pos);
void	rot_b_to_top(t_ctx *c, int pos);
int		pos_of_min(t_node *s);
int		pos_of_max(t_node *s);
void	sort_small(t_ctx *c);
void	simple_sort(t_ctx *c);
void	medium_sort(t_ctx *c);
void	complex_sort(t_ctx *c);
void	run_strategy(t_ctx *c);
t_strat	pick_by_disorder(double d);
void	print_bench(t_ctx *c);
void	print_counts(t_ctx *c, int from, int to);
void	print_label_strategy(t_ctx *c);
void	print_disorder(double d);
double	compute_disorder(t_node *a);
void	normalize(t_node *a);
#endif
