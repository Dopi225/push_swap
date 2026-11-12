/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:14:53 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/12 15:18:56 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	negatif(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi_safe(const char *s, int *out)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1 * negatif(s[i]);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	n = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		n = n * 10 + (s[i] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(n * sign);
	return (1);
}

int	add_back(t_node **a, int value)
{
	t_node	*n;
	t_node	*last;

	n = malloc(sizeof(t_node));
	if (!n)
		return (0);
	n->value = value;
	n->index = 0;
	n->next = NULL;
	if (!*a)
	{
		*a = n;
		return (1);
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = n;
	return (1);
}

int	has_duplicate(t_node *a)
{
	t_node	*j;

	while (a)
	{
		j = a->next;
		while (j)
		{
			if (j->value == a->value)
				return (1);
			j = j->next;
		}
		a = a->next;
	}
	return (0);
}
