/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 23:17:56 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:22:48 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *s, char c)
{
	size_t	w;

	w = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			while (*s != c && *s)
				s++;
			w++;
		}
		if (*s != '\0')
			s++;
	}
	return (w);
}

static void	freeall(char **split, size_t k)
{
	while (k >= 0)
	{
		free(split[k]);
		k--;
	}
	free(split);
}

static char	**main_malloc(char *str, char c, size_t i)
{
	char	**split;
	size_t	k;
	size_t	m;

	split = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	k = 0;
	while (k < count_words(str, c))
	{
		while (str[i] == c)
			i++;
		m = i;
		while (str[i] && str[i] != c)
			i++;
		split[k++] = ft_substr(str, (unsigned int) m, i - m);
		if (!split[k - 1])
		{
			freeall(split, k - 1);
			return (NULL);
		}
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**split;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	str = (char *) s;
	split = main_malloc(str, c, i);
	if (!split)
		return (NULL);
	return (split);
}
