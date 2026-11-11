/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:28:11 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 15:28:11 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_ops(t_ctx *c)
{
	c->op_names[SA] = "sa";
	c->op_names[SB] = "sb";
	c->op_names[SS] = "ss";
	c->op_names[PA] = "pa";
	c->op_names[PB] = "pb";
	c->op_names[RA] = "ra";
	c->op_names[RB] = "rb";
	c->op_names[RR] = "rr";
	c->op_names[RRA] = "rra";
	c->op_names[RRB] = "rrb";
	c->op_names[RRR] = "rrr";
}

int	error_exit(t_ctx *c)
{
	free_stack(&c->a);
	free_stack(&c->b);
	write(2, "Error\n", 6);
	return (1);
}

void	init_ctx(t_ctx *c)
{
	int	i;

	c->a = NULL;
	c->b = NULL;
	c->total = 0;
	c->bench = 0;
	c->strat = ADAPTIVE;
	c->disorder = 0.0;
	c->name = NULL;
	c->cplx = NULL;
	i = 0;
	while (i < 11)
	{
		c->count[i] = 0;
		c->op_names[i] = NULL;
		i++;
	}
	init_ops(c);
}

