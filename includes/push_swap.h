#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <limits.h>

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

#endif
