/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:53:40 by ekraujin          #+#    #+#             */
/*   Updated: 2021/12/09 13:56:12 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
	{
		ft_lstclear(&lst_new, del);
		return (NULL);
	}
	lst_new = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = ft_lstnew(f(lst->content));
		ft_lstadd_back(&lst_new, temp);
		temp = temp->next;
	}
	return (lst_new);
}
