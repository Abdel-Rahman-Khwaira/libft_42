/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:45:10 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/18 22:52:02 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first;
	t_list	*second;

	if (!lst || !del || !*lst)
		return ;
	first = *lst;
	second = first->next;
	del(first->content);
	free(first);
	while (second != NULL)
	{
		first = second;
		second = first->next;
		del(first->content);
		free(first);
	}
	*lst = NULL;
}
