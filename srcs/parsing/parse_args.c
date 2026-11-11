/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:17:23 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/10 13:17:23 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parse_option(t_ctx *c, char *arg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		c->strat = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		c->strat = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 9))
		c->strat = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 10))
		c->strat = ADAPTIVE;
	else if (!ft_strncmp(arg, "--bench", 7))
		c->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_args(t_ctx *c, int argc, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	while (i < argc)
	{
		if (!parse_option(c, argv[i]))
		{
			if (!ft_atoi_safe(argv[i], &nb) || !add_back(&c->a, nb))
				return (0);
		}
		i++;
	}
	return (!has_duplicate(c->a));
}
