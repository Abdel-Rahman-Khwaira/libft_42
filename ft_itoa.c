/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhwaira <akhwaira@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:58:35 by akhwaira          #+#    #+#             */
/*   Updated: 2026/10/22 16:11:05 by akhwaira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len_n(int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*res;
	unsigned int		len;

	len = len_n(n);
	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		while (len - 1)
		{
			res[--len] = -(n % 10) + 48;
			n /= 10;
		}
		return (res);
	}
	while (len)
	{
		res[--len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
