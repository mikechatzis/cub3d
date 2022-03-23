/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:07:23 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/30 20:05:18 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str1[255] = "Hello A";
// 	char str2[255] = "Hello Z";
// 	int size = 7;

// 	printf("My function %d\n", ft_strncmp(str1, str2, size));
// 	printf("Real function %d\n", strncmp(str1, str2, size));

// }