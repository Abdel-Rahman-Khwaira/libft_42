/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 18:02:56 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/18 23:56:17 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mainlst;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	mainlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&mainlst, del);
			return (NULL);
		}
		ft_lstadd_back(&mainlst, node);
		lst = lst->next;
	}
	return (mainlst);
}
