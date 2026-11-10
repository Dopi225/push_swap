/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:25:11 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 13:25:11 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *s)
{
	int	n;

	n = 0;
	while (s)
	{
		n++;
		s = s->next;
	}
	return (n);
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_node **s)
{
	t_node	*tmp;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}
