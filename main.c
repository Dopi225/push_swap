#include "./includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	c;

	if (argc < 2)
		return (0);
	init_ctx(&c);
	if (!parse_args(&c, argc, argv))
		return (error_exit(&c));
	if (!c.a)
		return (0);
	c.disorder = compute_disorder(c.a);
	normalize(c.a);
	if (!is_sorted(c.a))
		run_strategy(&c);
	if (c.bench)
		print_bench(&c);
	free_stack(&c.a);
	free_stack(&c.b);
	return (0);
}
