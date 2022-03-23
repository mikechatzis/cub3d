/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:13:01 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/30 21:12:37 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	s2;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	s2 = ft_strlen(needle);
	if (len == 0)
		return (0);
	while (haystack[i] != '\0' && (s2 + i) <= len)
	{	
		if (ft_strncmp(haystack + i, needle, s2) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main() 
// {
// 	char str[25] = "Foo Faz Faa"; 
// 	char ch[255] = "Faz"; 
// 	size_t size = 6;

// 	printf("%s\n", strnstr(str, ch, size));
// 	printf("%s\n", ft_strnstr(str, ch, size));
// }