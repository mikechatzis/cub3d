/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:02:26 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/30 16:54:23 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (src[j] && j < (dstsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main ()
// {
// 	char dest[] = "";
// 	// char dest2[] = "";
// 	char src[] = "Lenght of the full string is 31";
// 	size_t size = 5;

// 	printf("My function result: %lu %s\n", ft_strlcpy(dest, src, size), dest);
// 	// printf("Real function result: %lu\n", strlcpy(dest2, src, size));
// }