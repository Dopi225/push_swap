/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:59 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/24 15:52:23 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_checker(t_ctx *c)
{
	rotate_up(&c->a);
}

void	rb_checker(t_ctx *c)
{
	rotate_up(&c->b);
}

void	rr_checker(t_ctx *c)
{
	rotate_up(&c->a);
	rotate_up(&c->b);
}
