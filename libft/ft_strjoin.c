/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:22:05 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/07 22:49:23 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	size_t			s1_len;
	char			*strjoin;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	s1_len = (ft_strlen(s1) + ft_strlen(s2));
	strjoin = (char *)malloc(s1_len + 1);
	if (strjoin == 0)
		return (0);
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

// #include <stdio.h>
// int main()
// {
//     char s1[] = "Hello ";
//     char s2[] = "   .";
//     char *s3;

//     s3 = (char *)ft_strjoin(s1, s2);
//     printf("%s\n", s3);
// }