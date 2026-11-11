/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:24:34 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 14:24:34 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	simple_sort(t_ctx *c)
{
	while (stack_size(c->a) > 3)
	{
		rot_a_to_top(c, pos_of_min(c->a));
		pb(c);
	}
	sort_small(c);
	while (c->b)
		pa(c);
}
