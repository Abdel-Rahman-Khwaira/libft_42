/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:38:03 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:32:01 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	lens1;
	size_t	lens2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(lens1 + lens2 + 1);
	if (!str)
		return (NULL);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		str[i + lens1] = s2[i];
		i++;
	}
	str[i + lens1] = '\0';
	return (str);
}
