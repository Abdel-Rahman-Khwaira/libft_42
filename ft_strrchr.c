/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:25:15 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/15 15:05:55 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	c = (char) c;
	str = (char *)s;
	len = ft_strlen(s);
	len++;
	str += len - 1;
	while (len)
	{
		if (*str == c)
			return (str);
		len--;
		str--;
	}
	return (0);
}
