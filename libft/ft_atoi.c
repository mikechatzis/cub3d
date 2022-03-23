/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:13:51 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/22 18:49:22 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\t'
			|| nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-' )
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char s[] = "-123  H  45";
//     int rez = ft_atoi(s);
//     int rez2 = atoi(s);

//     printf("%d\n", rez);
//     printf("%d\n", rez2);
// }