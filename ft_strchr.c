/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:24:58 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/15 15:04:23 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	c = (char) c;
	str = (char *) s;
	len = ft_strlen(s);
	len++;
	while (len)
	{
		if (*str == c)
			return (str);
		len--;
		str++;
	}
	return (0);
}
