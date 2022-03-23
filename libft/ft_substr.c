/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:27:31 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/08 20:42:57 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (s[i] && i < len && (start + i) < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #include <stdio.h>
// int main()
// {
//     char str[] = "123456789";
//     char *str2;
//     size_t len = 0;

//     printf("str2 before: %s\n", str2);
//     str2 = ((char *)ft_substr(str, 4, len));
//     printf("str2 after: %s\n", str2);
// }