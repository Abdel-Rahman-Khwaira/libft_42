/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 00:27:32 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:33:08 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t len, size_t length, unsigned int start)
{
	if (start > length)
		return (0);
	if (len <= (length - start))
		return (len);
	return (length - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	length;
	size_t	minimum;
	size_t	i;

	if (!s)
		return (0);
	length = ft_strlen(s);
	minimum = min(len, length, start) + 1;
	sub = malloc(minimum);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < minimum - 1)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
