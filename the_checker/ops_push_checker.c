/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:35 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/24 16:42:14 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa_checker(t_ctx *c)
{
	push_top(&c->b, &c->a);
}

void	pb_checker(t_ctx *c)
{
	push_top(&c->a, &c->b);
}
