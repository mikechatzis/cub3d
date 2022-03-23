/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:23:46 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/08 15:41:01 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			counter++;
			i = 1;
		}
		if (*s == c)
			i = 0;
		s++;
	}
	return (counter);
}

static char	*dup_word(char const *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		start;
	char	**split;

	i = -1;
	j = 0;
	start = -1;
	if (!s)
		return (0);
	split = malloc((word_count(s, c) + 1) * (sizeof(char *)));
	if (!split)
		return (0);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			split[j++] = dup_word(s, start, i);
			start = -1;
		}
	}
	split[j] = 0;
	return (split);
}

// #include <stdio.h>
// int main()
// {
//     char **s;
// 	int i = 0;
//     char c = '\0';

//     s = ft_split("Test\0 Tsdadada\0dasda", c);
// 	while (i <= 0)
// 	{
// 		printf("%s\n", s[i]);
// 		i++;
// 	}
// }