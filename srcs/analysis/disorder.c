/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:21:16 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 13:21:16 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	pairs;

	mistakes = 0;
	pairs = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (pairs == 0)
		return (0.0);
	return ((double)mistakes / (double)pairs);
}
