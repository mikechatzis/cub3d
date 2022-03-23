/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:55:31 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/06 15:55:22 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	len;
	char			*s2;

	if (!s1 || !set)
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > i && ft_strchr(set, s1[len]))
		len--;
	s2 = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!s2)
		return (0);
	k = 0;
	len = (len - i + 1);
	while (k < len)
		s2[k++] = s1[i++];
	s2[k] = '\0';
	return (s2);
}

// #include <stdio.h>
// int main()
// {
//     char str[] = "HHHMy name is bugi?!H!HHHHH";
//     char rem[] = "H!";
//     char *str2;

//     printf("str1 =   %s\n", str);
//     str2 = ft_strtrim(str, rem);
//     printf("str2 =   %s\n", str2);
// }