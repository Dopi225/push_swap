/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:32:24 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/12 10:03:35 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rot_a_to_top(t_ctx *c, int pos)
{
	int	size;

	size = stack_size(c->a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(c);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(c);
	}
}

void	rot_b_to_top(t_ctx *c, int pos)
{
	int	size;

	size = stack_size(c->b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(c);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(c);
	}
}
