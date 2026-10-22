/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:24:52 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/15 14:36:06 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*cpy;

	cpy = (unsigned char *)dest;
	str = (unsigned char *)src;
	if (str < cpy)
	{
		cpy += n - 1;
		str += n - 1;
		while (n)
		{
			*cpy = *str;
			cpy--;
			str--;
			n--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
