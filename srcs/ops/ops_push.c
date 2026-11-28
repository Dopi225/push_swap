/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:35 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/24 16:28:49 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_ctx *c)
{
	push_top(&c->b, &c->a);
	log_op(c, PA);
}

void	pb(t_ctx *c)
{
	push_top(&c->a, &c->b);
	log_op(c, PB);
}
