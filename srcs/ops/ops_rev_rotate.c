/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:56:40 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 12:56:40 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_ctx *c)
{
	rotate_down(&c->a);
	log_op(c, RRA);
}

void	rrb(t_ctx *c)
{
	rotate_down(&c->b);
	log_op(c, RRB);
}

void	rr(t_ctx *c)
{
	rotate_down(&c->a);
	rotate_down(&c->b);
	log_op(c, RR);
}
