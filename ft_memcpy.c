/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <khwira.abd@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:24:48 by akhwaira          #+#    #+#             */
/*   Updated: 2026/09/29 02:15:46 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*cpy;

	cpy = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (n > 0)
	{
		*cpy = *str;
		cpy++;
		str++;
		n--;
	}
	return (dest);
}
