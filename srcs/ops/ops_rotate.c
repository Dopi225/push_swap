/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:59 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 12:55:59 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_ctx *c)
{
	rotate_up(&c->a);
	log_op(c, RA);
}

void	rb(t_ctx *c)
{
	rotate_up(&c->b);
	log_op(c, RB);
}

void	rr(t_ctx *c)
{
	rotate_up(&c->a);
	rotate_up(&c->b);
	log_op(c, RR);
}
