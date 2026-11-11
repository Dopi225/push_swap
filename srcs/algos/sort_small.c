/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:22:15 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 14:22:15 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_small(t_ctx *c)
{
	int	max;
	int	size;

	size = stack_size(c->a);
	if (size == 2 && c->a->index > c->a->next->index)
		sa(c);
	if (size != 3)
		return ;
	max = pos_of_max(c->a);
	if (max == 0)
		ra(c);
	else if (max == 1)
		rra(c);
	if (c->a->index > c->a->next->index)
		sa(c);
}
