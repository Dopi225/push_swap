/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boadopo <boadopo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:22:31 by boadopo           #+#    #+#             */
/*   Updated: 2026/10/31 03:09:39 by boadopo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptd;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)dest;
	ptd = (const unsigned char *)src;
	if (!ptr && !ptd)
		return (NULL);
	while (i < n)
	{
		ptr[i] = ptd[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <stdio.h>
 
#define MAX_LEN 80
 
char source[ MAX_LEN ] = "This is the source string";
char target[ MAX_LEN ] = "This is the target string";
 
int main(void)
{
  printf( "Before memcpy, target is \"%s\"\n", target );
  ft_memcpy( target, source, sizeof(source));
  printf( "After memcpy, target becomes \"%s\"\n", target );
}
*/
