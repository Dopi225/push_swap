/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:35 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 12:55:35 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_ctx *c)
{
	push_top(&c->b, &c->a);
	log_op(c, PB);
}

void	pb(t_ctx *c)
{
	push_top(&c->a, &c->b);
	log_op(c, PB);
}
