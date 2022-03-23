/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:52:53 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/26 19:05:21 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// #include <stdio.h>
// int main()
// {
// 	char chr = 'a';
// 	char chr2 = 'Z';

// 	printf("%c\n", ft_tolower(chr));
// 	printf("%c\n", ft_tolower(chr2));
// }