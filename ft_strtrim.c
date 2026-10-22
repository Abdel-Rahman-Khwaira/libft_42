/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:50:39 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:33:03 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lens1;
	size_t	i;
	char	*trimmed;

	i = 0;
	if (!s1 || !set)
		return (0);
	lens1 = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	while (ft_strchr(set, s1[lens1 - 1]) && lens1 > i)
		lens1--;
	trimmed = ft_substr(s1, i, lens1 - i);
	return (trimmed);
}
