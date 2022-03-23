/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:51:35 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/03 13:14:10 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned int	k;
	char			*s1;
	char			*s2;

	if (!src && !dest)
		return (0);
	i = 0;
	k = 0;
	s1 = (char *)dest;
	s2 = (char *)src;
	if (src < dest)
	{
		i = n - 1;
		k = n - 1;
		while (n--)
			s1[i--] = s2[k--];
	}
	else if (src >= dest)
	{
		while (n--)
			s1[i++] = s2[k++];
	}
	return (s1);
}
