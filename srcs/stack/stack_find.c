/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:26:59 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 13:26:59 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_of_min(t_node *s)
{
	int	pos;
	int	best;
	int	min;

	pos = 0;
	best = 0;
	min = s->index;
	while (s)
	{
		if (s->index < min)
		{
			min = s->index;
			best = pos;
		}
		pos++;
		s = s->next;
	}
	return (best);
}

int	pos_of_max(t_node *s)
{
	int	pos;
	int	best;
	int	min;

	pos = 0;
	best = 0;
	min = s->index;
	while (s)
	{
		if (s->index > min)
		{
			min = s->index;
			best = pos;
		}
		pos++;
		s = s->next;
	}
	return (best);
}
