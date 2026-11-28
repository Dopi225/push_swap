/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:25:42 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/23 12:25:44 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	complex_sort(t_ctx *c)
{
	int	n;
	int	max_bits;
	int	bit;
	int	i;

	n = stack_size(c->a);
	max_bits = 0;
	while (((n - 1) >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < n)
		{
			if (((c->a->index >> bit) & 1) == 0)
				pb(c);
			else
				ra(c);
			i++;
		}
		while (c->b)
			pa(c);
		bit++;
	}
}
