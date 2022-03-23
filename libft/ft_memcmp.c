/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:03:20 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/26 18:50:40 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;

	i = 0;
	ptr1 = (unsigned const char *)s1;
	ptr2 = (unsigned const char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s1[] = "aaaa";
//     char s2[] = "aaaa";
//     int ret;
//     int ret2;

//     ret = ft_memcmp(s1, s2, 4);
//     printf("%d\n", ret);

//     ret2 = memcmp(s1, s2, 4);
//     printf("%d\n", ret2);
// }