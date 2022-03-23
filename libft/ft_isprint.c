/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:12:50 by ekraujin          #+#    #+#             */
/*   Updated: 2021/11/26 18:49:45 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
// 	char chr = 'A';

// 	printf("%d\n", ft_isprint(chr));
// 	printf("%d\n", isprint(chr));
// }