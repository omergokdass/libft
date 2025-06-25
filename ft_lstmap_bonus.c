/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokdas <ogokdas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:48:32 by ogokdas           #+#    #+#             */
/*   Updated: 2025/06/23 12:48:32 by ogokdas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new_list;
	t_list	*current;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	start = lst;
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	current = new_list;
	while (start->next)
	{
		start = start->next;
		new_node = ft_lstnew(f(start->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		current->next = new_node;
		current = current->next;
	}
	return (new_list);
}
