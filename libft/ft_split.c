/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 03:16:39 by boadopo           #+#    #+#             */
/*   Updated: 2026/11/28 04:59:29 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static void	ft_free_all(char **tab, size_t n)
{
	while (n > 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
}

static char	**ft_fill(char **wrd, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		wrd[j] = ft_substr(s, start, i - start);
		if (!wrd[j])
			return (ft_free_all(wrd, j), NULL);
		j++;
	}
	return (wrd);
}

char	**ft_split(char const *s, char c)
{
	char	**wrd;

	if (!s)
		return (NULL);
	wrd = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!wrd)
		return (NULL);
	return (ft_fill(wrd, s, c));
}
