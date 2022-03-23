/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:51 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/26 18:51:06 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *)dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char src[50] = "Abcdefghjick";
//     char dst[50] = "123";
//     char dst2[50] = "321";
//     char *s1;
//     char *s2;
//     size_t size = 40;

//     printf("Dst before %s\n", dst);
//     s1 = ft_memcpy(dst, src, size);
//     printf("Dst after %s\n", s1);

//     printf("Dst before %s\n", dst2);
//     s2 = memcpy(dst2, src, size);
//     printf("Dst after %s\n", s2);
// }