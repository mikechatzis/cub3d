/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:06:18 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/26 21:51:16 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
// 	char chr = 'A';

// 	printf("%d\n", ft_isascii(chr));
// 	printf("%d\n", isascii(chr));
// }