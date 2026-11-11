/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.C                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:21:21 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 13:21:21 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	normalize(t_node *a)
{
	t_node	*i;
	t_node	*j;

	i = a;
	while (i)
	{
		i->index = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				i->index++;
			j = j->next;
		}
		i = i->next;
	}
}
