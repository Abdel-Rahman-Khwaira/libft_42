/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 02:03:20 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:13:23 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	c = (unsigned char) c;
	i = 0;
	str = (unsigned char *)s;
	while (n)
	{
		if (str[i] == c)
			return (&str[i]);
		n--;
		i++;
	}
	return (0);
}
