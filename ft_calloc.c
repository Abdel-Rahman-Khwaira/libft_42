/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:58:57 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:09:51 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	nbyte;

	if (nmemb && size)
	{
		if ((size > ((size_t) - 1) / nmemb))
			return (NULL);
	}
	nbyte = nmemb * size;
	mem = malloc(nbyte);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nbyte);
	return (mem);
}
