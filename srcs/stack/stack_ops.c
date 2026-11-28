/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:10:44 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/12 09:49:54 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_case(t_node **s)
{
	t_node	*first;
	t_node	*temp;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	temp = first->next;
	first->next = temp->next;
	temp->next = first;
	*s = temp;
}

void	push_top(t_node **from, t_node **to)
{
	t_node	*n;

	if (!*from)
		return ;
	n = *from;
	*from = n->next;
	n->next = *to;
	*to = n;
}

void	rotate_down(t_node **s)
{
	t_node	*prev;
	t_node	*last;

	if (!*s || !(*s)->next)
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rotate_up(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
}
