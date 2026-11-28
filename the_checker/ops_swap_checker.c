/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:55:09 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/24 16:42:23 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_checker(t_ctx *c)
{
	swap_case(&c->a);
}

void	sb_checker(t_ctx *c)
{
	swap_case(&c->b);
}

void	ss_checker(t_ctx *c)
{
	swap_case(&c->a);
	swap_case(&c->b);
}
