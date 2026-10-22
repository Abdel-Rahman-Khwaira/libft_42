/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:25:09 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/20 19:40:28 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!n)
		return (0);
	while (n && lens1 && lens2 && (s1[i] == s2[i]))
	{
		n--;
		lens1--;
		lens2--;
		i++;
	}
	if (!n && i)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
