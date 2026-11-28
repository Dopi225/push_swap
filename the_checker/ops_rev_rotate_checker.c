/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:56:40 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/24 15:52:19 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra_checker(t_ctx *c)
{
	rotate_down(&c->a);
}

void	rrb_checker(t_ctx *c)
{
	rotate_down(&c->b);
}

void	rrr_checker(t_ctx *c)
{
	rotate_down(&c->a);
	rotate_down(&c->b);
}
