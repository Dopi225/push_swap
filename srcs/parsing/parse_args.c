/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:17:23 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/28 04:17:50 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	parse_option(t_ctx *c, char *arg)
{
	if (!arg)
		return (0);
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

int	ft_parser_safe(t_ctx *c, const char *s)
{
	int		i;
	int		nb;
	char	**av;
	int		words;

	words = count_words(s);
	if (words > 1)
	{
		i = 0;
		av = ft_split_by_spaces(s);
		while (i < words)
		{
			if (!parse_option(c, av[i]))
			{
				if (!ft_atoi_safe(av[i], &nb) || !add_back(&c->a, nb))
				{
					ft_free_all(av, words);
					return (0);
				}
			}
			i++;
		}
		ft_free_all(av, words);
	}
	return (1);
}

int	parse_args(t_ctx *c, int argc, char **argv)
{
	int	i;
	int	nb;
	int	wrd;

	i = 1;
	while (i < argc)
	{
		wrd = count_words(argv[i]);
		if (wrd > 1)
		{
			if (!ft_parser_safe(c, argv[i]))
				return (0);
		}
		else if (wrd == 1)
		{
			if (!parse_option(c, argv[i]))
			{
				if (!ft_atoi_safe(argv[i], &nb) || !add_back(&c->a, nb))
					return (0);
			}
		}
		i++;
	}
	return (!has_duplicate(c->a));
}
