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

static void	*clear_control(t_list **new_lst, void (*del)(void *))
{
	ft_lstclear(new_lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_o;
	t_list	*new_lst;
	void	*n_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		n_content = f(lst->content);
		if (!n_content)
			return (clear_control(&new_lst, del));
		new_o = ft_lstnew(n_content);
		if (!new_o)
		{
			del(n_content);
			return (clear_control(&new_lst, del));
		}
		ft_lstadd_back(&new_lst, new_o);
		lst = lst->next;
	}
	return (new_lst);
}
