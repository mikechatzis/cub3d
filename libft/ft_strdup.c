/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:46:11 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/26 23:03:45 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*mem;

	i = 0;
	len = ft_strlen(s);
	mem = (char *)malloc(len + 1);
	if (mem == 0)
		return (0);
	while (i < len)
	{
		mem[i] = s[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

// #include <stdio.h>
// int main()
// {
// 	char s1[] = "Hi There P";
// 	char *s2;

// 	printf("%s ", s2);
// 	s2 = ((char *)ft_strdup(s1));
// 	printf("%s ", s2);
// }