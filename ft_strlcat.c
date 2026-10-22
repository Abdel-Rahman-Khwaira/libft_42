/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:25:01 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/18 23:50:05 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (len_src + size);
	while (src[i] != 0 && len_dest + i < size - 1)
	{
		dest[i + len_dest] = src[i];
		i++;
	}
	if (len_dest + i < size)
		dest[len_dest + i] = 0;
	return (len_dest + len_src);
}
