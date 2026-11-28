/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 15:01:10 by marigal           #+#    #+#             */
/*   Updated: 2026/11/26 10:31:17 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_words(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_spaces(str[i]) == 1)
			i++;
		if (str[i] && ft_is_spaces(str[i]) == 0)
			count++;
		while (str[i] && ft_is_spaces(str[i]) == 0)
			i++;
	}
	return (count);
}

void	ft_free_all(char **tab, size_t n)
{
	while (n > 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
}
