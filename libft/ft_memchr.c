/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:21:43 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/07 15:28:55 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s[] = "abcdefg";
//     // char find = ;
//     size_t size = 7;
//     char *rez;
//     char *rez2;

//     rez = ft_memchr(s, 'a', size);
//     printf("%s\n", rez);
//     rez2 = memchr(s, 'a', size);
//     printf("%s\n", rez2);
// }