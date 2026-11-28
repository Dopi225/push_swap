/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:33:01 by amartel           #+#    #+#             */
/*   Updated: 2026/11/26 10:24:18 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_count_words(char const *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (ft_is_spaces(*s) == 0 && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (ft_is_spaces(*s))
			in_word = 0;
		s++;
	}
	return (count);
}

static void	ft_free_error(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static char	*ft_word_dup(const char *s)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && ft_is_spaces(s[len]) == 0)
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, s, len);
	return (word);
}

static char	**ft_alloc(char const *s)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(ft_count_words(s) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

char	**ft_split_by_spaces(char const *s)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_alloc(s);
	if (!res)
		return (NULL);
	while (*s)
	{
		if (ft_is_spaces(*s) == 0)
		{
			res[i] = ft_word_dup(s);
			if (!res[i])
			{
				ft_free_error(res);
				return (NULL);
			}
			i++;
			while (*s && ft_is_spaces(*s) == 0)
				s++;
		}
		else
			s++;
	}
	return (res);
}
