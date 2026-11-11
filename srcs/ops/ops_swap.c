/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:09 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 12:55:09 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_ctx *c)
{
	swap_case(&c->a);
	log_op(c, SA);
}

void	sb(t_ctx *c)
{
	swap_case(&c->b);
	log_op(c, SB);
}

void	ss(t_ctx *c)
{
	swap_case(&c->a);
	swap_case(&c->b);
	log_op(c, SS);
}
