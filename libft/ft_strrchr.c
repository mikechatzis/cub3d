/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:01:27 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/07 21:43:10 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main () 
// {
//    const char str[] = "This is just a String"; 
//    const char ch = 'j'; 
//    printf("%s\n", strrchr(str, ch));
//    printf("%s\n", ft_strrchr(str, ch));
// }