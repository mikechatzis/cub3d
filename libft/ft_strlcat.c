/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:34:41 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/27 14:41:38 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		return (size + srclen);
	if (size == 0)
		return (srclen);
	while (dst[i])
		i++;
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char src[] = "Hello";
//     char dst1[255] = "Fellow";
//     size_t size = 7; 

//     printf("dst1: %lu %s\n", ft_strlcat(dst1, src, size), dst1);
//     // printf("dst2 before: %s\n", dst2);
//     // printf("dst2 after:%d %s\n",strlcat(dst2, src, 4), dst2);
// }