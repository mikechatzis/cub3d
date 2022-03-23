/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:39:58 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/01 11:13:27 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// #include <stdio.h>
// int main()
// {
// 	char chr = 'a';
// 	char chr2 = 'Z';

// 	printf("%c\n", ft_toupper(chr));
// 	printf("%c\n", ft_toupper(chr2));
// }