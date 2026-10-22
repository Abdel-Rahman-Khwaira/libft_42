/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:25:12 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/18 00:28:43 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenl;
	size_t	i;

	i = 0;
	if (!little || *little == 0)
		return ((char *)big);
	if (len <= 0)
		return (NULL);
	lenl = ft_strlen(little);
	while (len > 0 && big[i])
	{
		if ((lenl <= len) && !(ft_memcmp(&big[i], little, lenl)))
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (NULL);
}
