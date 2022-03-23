/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:56:25 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/07 22:41:53 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	int_len(long int n)
{	
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	else if (n < 0)
	{
		n = -n;
		len = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*positive(long int n, char *str, int len)
{
	while (len-- > 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

static char	*negative(long int n, char *str, int len)
{
	str[0] = '-';
	n = -n;
	while (len-- > 1)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*str;

	len = int_len(n);
	str = ft_calloc(len + 1, sizeof(*str));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = 0 + '0';
	else if (n < 0)
		str = negative(n, str, len);
	else if (n > 0)
		str = positive(n, str, len);
	return (str);
}
// #include <stdio.h>

// int main()
// {
// 	int n = -123487;
// 	char *str;

// 	str = ft_itoa(n);
// 	printf("%s\n", str);
// }