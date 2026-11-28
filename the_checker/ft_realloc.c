/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigal <marigal@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 10:47:21 by marigal           #+#    #+#             */
/*   Updated: 2026/11/26 16:52:22 by marigal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_realloc(char *pointer, int curr_size)
{
	char	*res;
	int		i;

	res = malloc(curr_size + BUFF_SIZE + 1);
	if (!res)
	{
		free(res);
		return (NULL);
	}
	if (!pointer)
		return (res);
	i = 0;
	while (i < curr_size)
	{
		res[i] = pointer[i];
		++i;
	}
	free(pointer);
	return (res);
}
