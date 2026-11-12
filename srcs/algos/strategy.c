/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:27:48 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/12 14:29:22 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_strat	pick_by_disorder(double d)
{
	if (d < 0.2)
		return (SIMPLE);
	if (d < 0.5)
		return (SIMPLE);
	return (SIMPLE);
}

void	run_strategy(t_ctx *c)
{
	t_strat	s;

	s = c->strat;
	c->name = "Adaptive";
	if (s == ADAPTIVE)
		s = pick_by_disorder(c->disorder);
	else if (s == SIMPLE)
		c->name = "Simple";
	if (s == SIMPLE)
		c->cplx = "O(n^2)";
	if (s == SIMPLE)
		simple_sort(c);
}
