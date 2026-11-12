/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:10:18 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/12 17:10:29 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	push_chunks(t_ctx *c, int chunk)
{
	int	pushed;

	pushed = 0;
	while (c->a)
	{
		if (c->a->index <= pushed)
		{
			pb(c);
			rb(c);
			pushed++;
		}
		else if (c->a->index <= pushed + chunk)
		{
			pb(c);
			pushed++;
		}
		else
			ra(c);
	}
}

void	medium_sort(t_ctx *c)
{
	int	chunk;

	chunk = ft_sqrt(stack_size(c->a)) * 2;
	push_chunks(c, chunk);
	while (c->b)
	{
		rot_b_to_top(c, pos_of_max(c->b));
		pa(c);
	}
}
