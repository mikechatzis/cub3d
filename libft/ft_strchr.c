/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:15:10 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/07 21:51:52 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char )c)
		return ((char *)s);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main () 
// {
//    const char str[] = "This is just a String"; 
//    const char ch = 'j'; 
//    printf("%s\n", strchr(str, ch));
//    printf("%s\n", ft_strchr(str, ch));
// }